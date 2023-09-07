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

void init_threadpool(threadpool *pool, int num_threads) {
    pool->tids = (pthread_t *)malloc(sizeof(pthread_t) * num_threads);
    pool->actives = num_threads;
    pool->queue = create_queue();
    pthread_mutex_init(&pool->mutex, NULL);
    pthread_cond_init(&pool->not_empty, NULL);


    for(int i = 0; i < pool->actives; i++) {
        pthread_create(pool->tids + i, NULL, worker, (void*)pool);
    }  
}

void* worker(void *arg) {
    threadpool *pool = (threadpool *)arg;
    while(1) {
        printf("it's the thread's turn\n");
        pthread_mutex_lock(&pool->mutex);
        printf("get the lock\n");
        while(is_empty(pool->queue)) {
            printf("block and wait for signal\n");
            pthread_cond_wait(&pool->not_empty, &pool->mutex);
        }
        printf("queue is not empty, get task\n");
        int task = deque(pool->queue);
        pthread_mutex_unlock(&pool->mutex);
        if(task == 0) {
            printf("terminate\n");
            return NULL;
        }
        // // sleep(task);
        printf("completed task: %d\n", task);
    }
}

void submit_task(threadpool *pool, int task) {
    pthread_mutex_lock(&pool->mutex);
    enque(pool->queue, task);
    pthread_cond_signal(&pool->not_empty);
    pthread_mutex_unlock(&pool->mutex);
}

void destroy(threadpool *pool) {
    printf("start destroying\n");
    for(int i = 0; i < pool->actives; i++) {
        submit_task(pool, 0);
    }

    for(int i = 0; i < pool->actives; i++) {
        pthread_join(pool->tids[i], NULL);
    }
}

int main() {
    threadpool pool;
    int num_threads = 5;
    init_threadpool(&pool, num_threads);

    //submit task
    for(int i = 0; i < pool.actives; i++) {
        submit_task(&pool, i+1);
        // sleep(1);
    }

    destroy(&pool);
    return 0;
}