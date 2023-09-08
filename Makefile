CC = gcc

all: prompt

prompt: 
	@echo "usage: make <target>"

queue_test.out: queue.test.c queue.c
	$(CC) queue.test.c queue.c -o $@

safe_queue_test.out: safe_queue_test.c safe_queue.c queue.c
	$(CC) safe_queue_test.c safe_queue.c queue.c -o $@

threadpool_test.out: threadpool_test.c threadpool.c safe_queue.c queue.c
	$(CC) threadpool_test.c threadpool.c safe_queue.c queue.c -o $@

clean:
	@echo "Cleaning up..." 
	rm *.out