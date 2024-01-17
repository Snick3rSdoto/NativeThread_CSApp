#include "erProc.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>


int Socket(int domain, int type, int protocol) {
    int res = socket(domain, type, protocol);
    if(res == -1) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }
    return res;
}

void Bind(int sockfd, const struct sockaddr* addr, socklen_t addrlen) {
    int res = bind(sockfd, addr, addrlen);
    if(res == -1) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
}

void Listen(int sockfd, int backlog) {
    int res = listen(sockfd, backlog);
    if(res == -1) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
}

int Accept(int sockfd, struct sockaddr* addr, socklen_t* adrlen) {
    int res = accept(sockfd, addr, adrlen);
    if(res == -1) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }
    return res;
}

void Connect(int sockfd, const struct sockaddr* addr, socklen_t addrlen) {
    int res = connect(sockfd, addr, addrlen);
    if(res == -1) {
        perror("Connect failed");
        exit(EXIT_FAILURE);
    }
}

void Inet_pton(int af, const char* src, void* dst) {
    int res = inet_pton(af, src, dst);
    if(res == 0) {
        std::cout << "Inet_pton failed: src does not contain a character" 
                    " string representing a valid network address in the specified"
                    " addres family\n";
        exit(EXIT_FAILURE);
    } else if(res == -1) {
        perror("Inet_pton failed");
        exit(EXIT_FAILURE);
    }

}