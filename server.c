#include <stdio.h>
#include <stdlib.h> //files required for socket programming
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>

#define BACKLOG 10
// the number of clients that can connect at a time

int main(int argc, char **argv)
{
    if (argc != 2)
    { // port is not given
        printf("Usage: %s <port>\n", argv[0]);
        exit(0);
    }
    //port given at run time

    int port = atoi(argv[1]);
    //ascii to integer
    printf("Port: %d\n", port);

    int n_client = 0;
    //to count the number of clients
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    //socket file descriptor
    //SOCK_STREAM- tcp
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);

    bind(sockfd, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
    printf("[+]Bind\n");

    listen(sockfd, BACKLOG);
    printf("[+]Listening for the client\n");
    //server has started

    int i = 1;
    while (i)
    {
        int client_socket = accept(sockfd, NULL, NULL);
        n_client++;
        time_t currentTime;
        time(&currentTime);
        printf("Client %d requested for time at %s", n_client, ctime(&currentTime));
        send(client_socket, ctime(&currentTime), 30, 0);
    }
    return 0;
}