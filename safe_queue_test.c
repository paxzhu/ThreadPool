 /* 在 UNIX 系统下编译和运行这段代码：
 *
 * unix> gcc safe_queue_test.c safe_queue.c queue.c -o safe_queue_test
 * unix> ./safe_queue_test
 */

#include "safe_queue.h"
#include <assert.h>


int main() {
    Safe_Queue* safe_que = create_safe_que();
    safe_enque(safe_que, 10);
    assert (safe_deque(safe_que) == 10);
    assert (is_empty(safe_que->queue) == 1);
    safe_deque(safe_que);
    
    return 0;
}