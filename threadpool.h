#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include "safe_queue.h"
#define END_TASKS_SIGNAL -1

typedef void Handler(int);
typedef struct {
    int actives;
    Handler* handler; 
    pthread_t* tids;
    SafeQueue* safe_que;
} ThreadPool;

ThreadPool* init_threadpool(int num_threads, Handler* handler);
void submit_task(ThreadPool* pool, T task);
void* worker(void*);
void destory(ThreadPool* pool);

#endif