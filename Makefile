CC = gcc

.PHONY: server.out client.out 

all: prompt

prompt: 
	@echo "usage: make <target>"

queue_test.out: queue.test.c queue.c
	$(CC) queue.test.c queue.c -o $@

safe_queue_test.out: safe_queue_test.c safe_queue.c queue.c
	$(CC) safe_queue_test.c safe_queue.c queue.c -o $@

threadpool_test.out: threadpool_test.c threadpool.c safe_queue.c queue.c
	$(CC) threadpool_test.c threadpool.c safe_queue.c queue.c -o $@

server.out: server.c csapp.c safe_queue.c queue.c echo_with_sleep.c
	$(CC) server.c csapp.c safe_queue.c queue.c echo_with_sleep.c -o server.out

client.out: 
	$(CC) client.c threadpool.c safe_queue.c queue.c csapp.c -o client.out

clean:
	@echo "Cleaning up..." 
	rm *.out