#ifndef __SAFE_QUEUE_H__
#define __SAFE_QUEUE_H__

#include <pthread.h>
#include "queue.h"

typedef struct {
    Queue* queue;
    pthread_mutex_t mutex;
    pthread_cond_t not_empty;
} SafeQueue;

SafeQueue* create_safe_que();
void safe_enque(SafeQueue* safe_que, T data);
T safe_deque(SafeQueue* safe_que);
void safe_clear(SafeQueue* safe_que);

#endif
