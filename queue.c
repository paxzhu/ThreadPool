#include "queue.h"

Node* create_node(T data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Queue* create_queue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

int is_empty(Queue* queue) {
    return queue->head == NULL;
}

void enque(Queue* queue, T data) {
    Node* newNode = create_node(data);
    if(queue->tail == NULL) {
        queue->head = newNode;
        queue->tail = newNode;
    }
    else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
}

T deque(Queue* queue) {
    if(is_empty(queue)) {
        printf("Error: queue is empty!\n");
        return -1;
    }

    Node* temp = queue->head;
    T deque_num = temp->data;
    queue->head = temp->next;
    free(temp);

    if(is_empty(queue)) {
        queue->tail = NULL;
    }
    return deque_num;
}

T peek(Queue* queue) {
    if(is_empty(queue)) {
        printf("queue is empty\n");
        return -1;
    }
    return queue->head->data;
}
