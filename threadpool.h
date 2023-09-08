#include "safe_queue.h"
#define END_TASKS_SIGNAL 0

typedef struct {
    int actives;
    pthread_t* tids;
    Safe_Queue* safe_que;
} ThreadPool;

ThreadPool* init_threadpool(int num_threads);
void submit_task(ThreadPool* pool, T task);
void* worker(void*);
void destory(ThreadPool* pool);