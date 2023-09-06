
#include "../queue.h"

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
