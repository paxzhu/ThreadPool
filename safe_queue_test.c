#include "safe_queue.h"
#include <assert.h>


void *worker(void* arg) {
    SafeQueue* safe_que = arg;
    while(1) {
        sleep(1);
        int task = safe_deque(safe_que);
        printf("comleted task: %d\n", task);
    }
}

int main() {
    SafeQueue* safe_que = create_safe_que();
    //activate worker
    pthread_t tid;
    pthread_create(&tid, NULL, worker, safe_que);

    //producer
    for(int i = 1; i < 6; i++) {
        sleep(2);
        safe_enque(safe_que, i);
        printf("submit task: %d\n", i);
    }
    
    sleep(10);
    safe_clear(safe_que);
    return 0;
}