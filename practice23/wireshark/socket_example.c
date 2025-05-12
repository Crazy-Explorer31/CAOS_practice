#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <arpa/inet.h>


int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s NODE SERVICE\n", argv[0]);
        return 1;
    }

    struct addrinfo hints = { .ai_family = AF_INET, .ai_socktype = SOCK_STREAM };
    struct addrinfo *addrs = NULL;

    int res = getaddrinfo(argv[1], argv[2], &hints, &addrs);
    if (res) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(res));
        return 1;
    }

    int fd = socket(PF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        perror("socket");
        return 1;
    }

    res = connect(fd, addrs->ai_addr, sizeof(struct sockaddr_in));
    if (res < 0) {
        perror("connect");
        return 1;
    }

    struct sockaddr_in *inet;
    inet = (struct sockaddr_in *)addrs->ai_addr;
    char buf[1024];
    printf("\taddress ipv4: %s, port: %hu\n",
        inet_ntop(addrs->ai_family, &inet->sin_addr,
            buf, sizeof(buf)),
        ntohs(inet->sin_port));

    // char msg[] = "HI!\n";
    // write(fd, msg, sizeof(msg));

    char header[1000] = {0};
    sprintf(header, "GET / HTTP/1.0\r\nHost: www.%s\r\n\r\n", argv[1]);
    printf("%s\n", header);
    write(fd, header, strlen(header));


    char c;
    while (read(fd, &c, 1) == 1) {
        write(1, &c, 1);
    }

    close(fd);
    freeaddrinfo(addrs);
}
