#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "erProc.h"

#define SERVER_IP "127.0.0.1"
#define DEFAULT_PORT 11111
#define BUFFER_SIZE 256

int main() {
    int fd = Socket(AF_INET, SOCK_STREAM, 0);
 
    struct sockaddr_in adr;
    adr.sin_family = AF_INET;
    adr.sin_port = htons(DEFAULT_PORT);
    adr.sin_addr.s_addr = htons(INADDR_ANY);

    Inet_pton(AF_INET, SERVER_IP, &adr.sin_addr);

    Connect(fd, reinterpret_cast<sockaddr*>(&adr), sizeof(adr));
    
    send(fd, "Hello Server", 12, 0);

    return 0;
}