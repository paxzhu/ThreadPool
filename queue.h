#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include "csapp.h"

typedef int T;

typedef struct Node{
    T data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} Queue;

Node* create_node(T data);
Queue* create_queue();
int is_empty(Queue* queue);
void enque(Queue* queue, T data);
T deque(Queue* queue);
T peek(Queue* queue);
void clear(Queue* queue);

#endif