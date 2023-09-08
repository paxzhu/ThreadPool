#include <pthread.h>
#include "queue.h"

typedef struct {
    Queue* queue;
    pthread_mutex_t mutex;
    pthread_cond_t not_empty;
} Safe_Queue;

Safe_Queue* create_safe_que();
void safe_enque(Safe_Queue* safe_que, T data);
T safe_deque(Safe_Queue* safe_que);
void safe_clear(Safe_Queue* safe_que);
