#include "threadpool.h"
#include "csapp.h"

#define ACTIVES 5
// char *messages[] = {
//     "Simplicity is prerequisite for reliability.\n",
//     "Hello, world!\n",
//     "All problems in computer science can be solved by another level of indirection.\n",
//     "It's harder to read code than to write it.\n",
//     "Don't reapeat yourself. Every piece of knowledge must have a single, unambiguous, authoritative representation within a system.\n",
//     "There are two hard things in computer science: cache invalidation, naming things, and off-by-one errors.\n",
//     "Good code is its own best documentation. As you're about to add a comment, ask yourself, 'How can I improve the code so that this comment isn't needed?'\n",
//     "First, solve the problem. Then, write the code.\n",
//     "Any fool can write code that a computer can understand. Good programmers write code that humans can understand.\n",
//     "In order to be irreplaceable, one must always be different.\n",
//     "Java is to JavaScript what car is to Carpet.\n",
//     "Knowledge is power.\n",
//     "Code is like humor. When you have to explain it, it's bad.\n",
//     "Fix the cause, not the symptom.\n",
//     "Simplicity is the soul of efficiency.\n"
// };

// char *messages[] = {
//     "message 0\n", "message 1\n", "message 2\n", "message 3\n", "message 4\n","message 5\n", "message 6\n", "message 7\n", "message 8\n", "message 9\n", "message 10\n",
//     "message 11\n", "message 12\n", "message 13\n", "message 14\n","message 15\n", "message 16\n", "message 17\n", "message 18\n", "message 19\n", "message 20\n"
// };

char *messages[] = {
    "message 0", "message 1", "message 2", "message 3", "message 4","message 5", "message 6", "message 7", "message 8", "message 9", "message 10",
    "message 11", "message 12", "message 13", "message 14","message 15", "message 16", "message 17", "message 18", "message 19", "message 20"
};

char *servaddr = "localhost";
int servport = 8888;

void send_messages(int index) {
    int clientfd;
    char buf[MAXLINE];
    rio_t rio;

    clientfd = Open_clientfd(servaddr, servport);
    Rio_readinitb(&rio, clientfd);
    //send to server,
    // printf("message: %s, len: %ld\n", messages[index], strlen(messages[index]));
    Rio_writen(clientfd, messages[index], strlen(messages[index]));
    printf("================\n");
    //receive the echo from the server
    Rio_readlineb(&rio, buf, MAXLINE);
    printf("------%s--------\n", buf);
    Fputs(buf, stdout);

    Close(clientfd);        
}

int main() {
    ThreadPool* pool = init_threadpool(ACTIVES, send_messages);
    
    // submit tasks
    for(int i = 0; i < 15; i++) {
        // printf("messages[%d]: %s\n", i, messages[i]);
        submit_task(pool, i);
    }

    // destory
    destory(pool);
}

