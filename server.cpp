#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <cstring>
#include <algorithm>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

std::vector<int> clients;
std::mutex clients_mutex;

void broadcastMessage(const std::string &message, int senderSocket) {
    std::lock_guard<std::mutex> lock(clients_mutex);
    for (int clientSocket : clients) {
        if (clientSocket != senderSocket) {
            send(clientSocket, message.c_str(), message.size(), 0);
        }
    }
}

void handleClient(int clientSocket) {
    char buffer[BUFFER_SIZE];

    while (true) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE, 0);

        if (bytesReceived <= 0) {
            std::cout << "Client disconnected\n";
            close(clientSocket);
            break;
        }

        std::string message(buffer);
        std::cout << "Message: " << message << std::endl;

        broadcastMessage(message, clientSocket);
    }

    std::lock_guard<std::mutex> lock(clients_mutex);
    clients.erase(std::remove(clients.begin(), clients.end(), clientSocket), clients.end());
}

int main() {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 5);

    std::cout << "Server started on port " << PORT << std::endl;

    while (true) {
        int clientSocket = accept(serverSocket, nullptr, nullptr);

        std::lock_guard<std::mutex> lock(clients_mutex);
        clients.push_back(clientSocket);

        std::thread t(handleClient, clientSocket);
        t.detach();
    }

    close(serverSocket);
    return 0;
}