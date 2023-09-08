#include "threadpool.h"

int main() {
    int num_threads = 5;
    ThreadPool* pool = init_threadpool(num_threads);

    for(int i = 1; i < 9; i++) {
        submit_task(pool, i);
    }

    destory(pool);
    return 0;
}