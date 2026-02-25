# TCP Multi-Client Chat Application (C++)

## 📌 Overview

A multithreaded TCP client-server chat application built using C++ and
BSD socket APIs on Linux (Ubuntu via WSL).\
This project demonstrates practical implementation of socket
programming, multithreading, mutex synchronization, and real-time
message broadcasting.

------------------------------------------------------------------------

## 🚀 Features

-   TCP socket-based communication
-   Multi-client support using `std::thread`
-   Mutex synchronization (`std::mutex`) for shared resource protection
-   Real-time message broadcasting
-   Linux-based POSIX socket implementation
-   Concurrent client handling

------------------------------------------------------------------------

## 🛠 Technologies Used

-   C++
-   POSIX Sockets (BSD Sockets API)
-   Multithreading (`std::thread`)
-   Mutex (`std::mutex`)
-   Linux (Ubuntu WSL)
-   GCC Compiler

------------------------------------------------------------------------

## 🧠 Architecture

Client 1\
Client 2 ---\> Server ---\> Broadcast to all connected clients\
Client 3

-   The server listens on a TCP port.
-   Each client connection is handled in a separate thread.
-   Messages from one client are broadcast to all other connected
    clients.

------------------------------------------------------------------------

## ⚙️ How to Compile and Run

### Step 1: Compile

``` bash
g++ server.cpp -o server -pthread
g++ client.cpp -o client -pthread
```

### Step 2: Run Server

``` bash
./server
```

### Step 3: Run Clients (in separate terminals)

``` bash
./client
```

------------------------------------------------------------------------

## 🔍 Concepts Demonstrated

-   TCP 3-Way Handshake (Connection Establishment)
-   Socket Lifecycle: `socket()`, `bind()`, `listen()`, `accept()`,
    `connect()`
-   Data Transmission: `send()`, `recv()`
-   Concurrency using Threads
-   Race Condition Prevention using Mutex
-   Client Connection Management

------------------------------------------------------------------------

## 📈 Resume Description

TCP Multi-Client Chat Application \| C++, Socket Programming,
Multithreading\
- Built a TCP-based concurrent chat system using BSD sockets on Linux.\
- Implemented thread-based client handling with mutex synchronization.\
- Designed broadcast messaging architecture for real-time multi-user
communication.\
- Demonstrated understanding of TCP/IP, concurrency, and system-level
debugging.

------------------------------------------------------------------------

## 📄 License

This project is created for educational and learning purposes.

------------------------------------------------------------------------

## 📸 Screenshots

### 🖥️ Server Started
![Server Running](screenshots/image.png)

---

### 💬 Client 1 Connected
![Client 1](screenshots/image-1.png)

---

### 💬 Client 2 Connected
![Client 2](screenshots/image-2.png)

---

### 🔁 Message Broadcasting
![Message Broadcast](screenshots/image-3.png)

------------------------------------------------------------------------