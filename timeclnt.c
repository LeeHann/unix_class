#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

#define oops(msg) {perror(msg); exit(1);}

int main(int ac, char *av[])
{
    struct sockaddr_in servadd;
    struct hostent *hp;
    int sock_id, sock_fd;
    int messlen;
    char message[BUFSIZ];

    //Step 1 : Get a socket
    sock_id = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_id == -1)
        oops("socket");

    //Step 2 : connect to server
    bzero(&servadd, sizeof(servadd));
    
    servadd.sin_addr.s_addr = inet_addr(av[1]);
    servadd.sin_port = htons(atoi(av[2]));
    servadd.sin_family = AF_INET;

    if(connect(sock_id, (struct sockaddr *) &servadd, sizeof(servadd)) != 0)
        oops("connect");

    //Step 3 : transfer data from server, then hang up
    messlen = read(sock_id, message, BUFSIZ);
    if(messlen == -1)
        oops("read");

    if(write(1, message, messlen) != messlen)
        oops("write");

    close(sock_id);
    return 0;
}
