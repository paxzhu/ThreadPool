#include "queue.h"

struct Node* createNode(T data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

int isEmpty(struct Queue* queue) {
    return queue->head == NULL;
}

void enque(struct Queue* queue, T data) {
    struct Node* newNode = createNode(data);
    if(queue->tail == NULL) {
        queue->head = newNode;
        queue->tail = newNode;
    }
    else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
}

T deque(struct Queue* queue) {
    if(isEmpty(queue)) {
        printf("Error: queue is empty!\n");
        return -1;
    }

    struct Node* temp = queue->head;
    int deque_num = temp->data;
    queue->head = temp->next;
    free(temp);

    if(isEmpty(queue)) {
        queue->tail = NULL;
    }
    return deque_num;
}

T peek(struct Queue* queue) {
    if(isEmpty(queue)) {
        printf("queue is empty\n");
        return -1;
    }
    return queue->head->data;
}
