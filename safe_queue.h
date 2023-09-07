#include <pthread.h>
#include "queue.h"

typedef struct {
    int actives;
    pthread_t *tids;
    Queue *queue;
    pthread_mutex_t mutex;
    pthread_cond_t not_empty;
} threadpool;

void init_threadpool(threadpool *pool, int num_threads);
void* worker(void*);
void submit_task(threadpool *pool, int task);
void destroy(threadpool *pool);