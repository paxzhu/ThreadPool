 /* 在 UNIX 系统下编译和运行这段代码：
 *
 * unix> gcc safe_queue_test.c safe_queue.c queue.c -o safe_queue_test
 * unix> ./safe_queue_test
 */

#include "safe_queue.h"

void test_submit_int(threadpool *pool) {
    for(int i = 0; i < pool->actives; i++) {
        submit_task(pool, i+1);
        // sleep(1);
    }

    destroy(pool);
}

void test_submit_struct(threadpool *pool) {
    for(int i = 0; i < pool->actives; i++) {
        submit_task(pool, i+1);
        // sleep(1);
    }

    destroy(pool);
}

int main() {
    threadpool pool;
    int num_threads = 5;
    init_threadpool(&pool, num_threads);

    // submit int input
    test_submit_int(&pool);

    // submit struct input
    // test_submit_struct(&pool);

    return 0;
}