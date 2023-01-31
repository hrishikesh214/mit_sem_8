#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int sockfd;
    int len;
    struct sockaddr_in address;
    int result, count;
    char readBuffer[80], writeBuffer[80], exitTemp[] = "exit\n";
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = 9129;
    len = sizeof(address);
    result = connect(sockfd, (struct sockaddr *)&address, len);
    if (result == -1)
    {
        printf("[me] error\n");
        exit(1);
    }
    printf("[me] connected to server");

    while (1)
    {
        fflush(stdout);
        printf("\nenter string: ");
        fgets(writeBuffer, 80, stdin);

        write(sockfd, writeBuffer, strlen(writeBuffer) + 1);

        if (strcmp(writeBuffer, exitTemp) == 0)
            break;
        count = read(sockfd, readBuffer, 20);
        printf("\n[server] ");
        printf("%s", readBuffer);
    }

    close(sockfd);
    exit(0);
}
