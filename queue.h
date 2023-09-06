#include <stdio.h>
#include <stdlib.h>

typedef int T;

struct Node {
    T data;
    struct Node* next;
};

struct Queue {
    struct Node* head;
    struct Node* tail;
};

struct Queue* createQueue();
int isEmpty(struct Queue* queue);
void enque(struct Queue* queue, T data);
T deque(struct Queue* queue);
T peek(struct Queue* queue);