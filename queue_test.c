 /* 在 UNIX 系统下编译和运行这段代码：
 *
 * unix> gcc queue_test.c queue.c -o queue_test
 * unix> ./queue_test
 */

#include <assert.h>
#include "queue.h"

int main() {
    Queue* queue = create_queue();

    enque(queue, 10);
    enque(queue, 20);
    enque(queue, 30);
    assert (peek(queue) == 10);
    assert (is_empty(queue) == 0);
    assert (peek(queue) == 10);
    assert (deque(queue) == 10);
    assert (peek(queue) == 20);
    assert (deque(queue) == 20);
    assert (peek(queue) == 30);
    assert (deque(queue) == 30);
    assert (is_empty(queue) == 1);

    enque(queue, 0);
    enque(queue, 20);
    enque(queue, 40);
    assert (peek(queue) == 0);
    assert (is_empty(queue) == 0);
    clear(queue);
    assert (is_empty(queue) == 1);
    return 0;
}
