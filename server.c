#include "safe_queue.h"
#include "csapp.h"

#define ACTIVES 5

void* worker(void *arg);
void echo(int connfd);

int main(int argc, char **argv) {
    if(argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(0);
    }

    int listenfd, port, connfd;
    struct sockaddr_in clientaddr;
    socklen_t clientlen = sizeof(struct sockaddr_in);
    pthread_t tid;
    SafeQueue* safe_que = create_safe_que();
    port = atoi(argv[1]);
    listenfd = Open_listenfd(port);

    for(int i = 0; i < ACTIVES; i++) {
        pthread_create(&tid, NULL, worker, safe_que);
    }

    //producer
    while(1) {
        connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
        safe_enque(safe_que, connfd);
    }
}

void* worker(void *arg) {
    SafeQueue* safe_que = arg;
    while (1) {
        int connfd = safe_deque(safe_que);
        //handler
        echo(connfd);
        Close(connfd);
    }
}