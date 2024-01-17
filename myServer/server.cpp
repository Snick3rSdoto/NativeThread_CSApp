#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "erProc.h"

#define DEFAULT_PORT 11111
#define BUFFER_SIZE 256


int main() {
    int server = Socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in adr;

    adr.sin_family = AF_INET;
    adr.sin_port = htons(DEFAULT_PORT);
    adr.sin_addr.s_addr = htons(INADDR_ANY);

    Bind(server, reinterpret_cast<sockaddr*>(&adr), sizeof(adr));

    Listen(server, 1);

    socklen_t adrlen = sizeof(adr);
    int fd = Accept(server, reinterpret_cast<sockaddr*>(&adr), &adrlen);

    char buf[BUFFER_SIZE];
    recv(fd, buf, BUFFER_SIZE, 0);
    std::cout << buf << std::endl;
    
    return 0;
}