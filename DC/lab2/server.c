#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>

struct thread_data
{
    int client_sockfd;
    int *cids;
};

void *server_thread(void *arg)
{
    int client_sockfd;
    char readBuffer[80], writeBuffer[80];
    int count = 0;

    struct thread_data *my_data = (struct thread_data *)arg;
    client_sockfd = my_data->client_sockfd;

    while (1)
    {
        count = read(client_sockfd, readBuffer, 20);
        readBuffer[count] = '\0';

        if (strcmp(readBuffer, "exit") == 0)
        {
            printf("\n[server] client %d disconnected", client_sockfd);
            break;
        }

        printf("\n[client %d] %s\n", client_sockfd, readBuffer);

        sprintf(writeBuffer, "[client %d] %s", client_sockfd, readBuffer);

        // broadcast to all clients
        for (int i = 0; i < 10; i++)
        {
            if (my_data->cids[i] != 0)
            {
                write(my_data->cids[i], writeBuffer, strlen(writeBuffer) + 1);
            }
        }

        write(client_sockfd, writeBuffer, strlen(writeBuffer) + 1);
    }

    printf("\n[server] client %d disconnected", client_sockfd);
    close(client_sockfd);
    pthread_exit(NULL);
}

int main()
{
    int server_sockfd, client_sockfd, cids[10] = {0}, cidsp = 0;
    int server_len, client_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    pthread_t t;
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = 9129;
    server_len = sizeof(server_address);
    if (bind(server_sockfd, (struct sockaddr *)&server_address, server_len) == -1)
    {
        printf("\n[server] error");
        exit(1);
    }
    printf("\n[server] waiting....");
    listen(server_sockfd, 5);
    while (1)
    {
        struct thread_data *my_data = (struct thread_data *)malloc(sizeof(struct thread_data));
        my_data->client_sockfd = client_sockfd;
        my_data->cids = cids;

        client_len = sizeof(client_address);
        client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len);
        printf("\n[server] created new client thread  %d", client_sockfd);
        pthread_create(&t, NULL, server_thread, (void *)my_data);

        cids[cidsp++] = client_sockfd;
    }
    return 0;
}