#include "threadpool.h"

ThreadPool* init_threadpool(int num_threads) {
    ThreadPool *pool = (ThreadPool *)malloc(sizeof(ThreadPool));
    pool->actives = num_threads;
    pool->tids = (pthread_t *)malloc(sizeof(pthread_t) * num_threads);
    pool->safe_que = create_safe_que();

    for(int i = 0; i < pool->actives; i++) {
        pthread_create(pool->tids + i, NULL, worker, (void*)pool);
    }
    return pool;
}

void* worker(void* arg) {
    ThreadPool* pool = (ThreadPool*)arg;
    while (1) {
        T task = safe_deque(pool->safe_que);
        if(task == 0) {
            return NULL;
        }
        sleep(10-task);
        printf("completed task: %d\n", task);
    }
}

void submit_task(ThreadPool* pool, T task) {
    safe_enque(pool->safe_que, task);
}

void destory(ThreadPool* pool) {
    for(int i = 0; i < pool->actives; i++) {
        submit_task(pool, END_TASKS_SIGNAL);
    }

    for(int i = 0; i < pool->actives; i++) {
        pthread_join(pool->tids[i], NULL);
    }

    free(pool->tids);
    safe_clear(pool->safe_que);
    free(pool);
}