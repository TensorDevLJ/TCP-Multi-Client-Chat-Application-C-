#include <iostream>
#include <thread>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void receiveMessages(int sock) {
    char buffer[BUFFER_SIZE];

    while (true) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytesReceived = recv(sock, buffer, BUFFER_SIZE, 0);

        if (bytesReceived <= 0) {
            std::cout << "Disconnected from server\n";
            break;
        }

        std::cout << "\nMessage: " << buffer << std::endl;
    }
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

    connect(sock, (sockaddr*)&serverAddr, sizeof(serverAddr));

    std::thread receiver(receiveMessages, sock);

    std::string message;
    while (true) {
        std::getline(std::cin, message);
        send(sock, message.c_str(), message.size(), 0);
    }

    receiver.join();
    close(sock);
    return 0;
}