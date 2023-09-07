 /* 在 UNIX 系统下编译和运行这段代码：
 *
 * unix> gcc queue_test.c queue.c -o queue_test
 * unix> ./queue_test
 */

#include "queue.h"

int main() {
    struct Queue* queue = createQueue();

    enque(queue, 10);
    enque(queue, 20);
    enque(queue, 30);

    printf("head of the queue: %d\n", peek(queue));

    printf("deque_num = %d\n", deque(queue));
    printf("deque_num = %d\n", deque(queue));
    printf("deque_num = %d\n", deque(queue));

    return 0;
}
