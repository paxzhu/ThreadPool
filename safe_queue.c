#include "safe_queue.h"

Safe_Queue* create_safe_que() {
    Safe_Queue* safe_que = (Safe_Queue *)malloc(sizeof(Safe_Queue));
    // printf("declare the safe_que\n");
    safe_que->queue = create_queue();
    // printf("initialize the safe_queue\n");
    pthread_mutex_init(&safe_que->mutex, NULL);
    pthread_cond_init(&safe_que->not_empty, NULL);
    return safe_que;
}

void safe_enque(Safe_Queue* safe_que, T data) {
    pthread_mutex_lock(&safe_que->mutex);
    enque(safe_que->queue, data);
    pthread_cond_signal(&safe_que->not_empty);
    pthread_mutex_unlock(&safe_que->mutex);
}

T safe_deque(Safe_Queue* safe_que) {
    pthread_mutex_lock(&safe_que->mutex);
    while(is_empty(safe_que->queue)) {
        printf("safe_queue is empty!wait please!\n");
        pthread_cond_wait(&safe_que->not_empty, &safe_que->mutex);
    }
    T deque_num = deque(safe_que->queue);
    pthread_mutex_unlock(&safe_que->mutex);
    return deque_num;
}

void safe_clear(Safe_Queue* safe_que) {
    pthread_mutex_lock(&safe_que->mutex);
    clear(safe_que->queue);
    pthread_mutex_unlock(&safe_que->mutex);
}