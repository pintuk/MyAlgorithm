#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define QUEUE_SIZE	10

int Queue[QUEUE_SIZE];
int front = -1;
int rear = -1;

void enqueue(int item)
{
	rear = rear + 1;
	if(rear >= QUEUE_SIZE) {
		printf("Queue is full....\n");
		return;
	}
	Queue[rear] = item;
}

void dequeue(int *item)
{
	if(front == rear) {
		printf("Queue is empty....\n");
		return;
	}
	front = front + 1;
	*item = Queue[front];
}

void PrintQueue(void)
{
	int i=0;
	printf("Content of Queue:\n");
	if(QueueEmpty()) {
		printf("Queue is Empty....\n");
		return;
	}
		
	for(i=front; i<=rear; i++) {
		printf("%d <-- ",Queue[i]);
	}
	printf("\n\n");
}

int QueueEmpty()
{
	if(front == rear) return 1;
	else
	return 0;
}

int main()
{
	int i=0;
	int item=0;

	front = 0;

	for(i=1; i<QUEUE_SIZE; i++) {
		enqueue(i);
	}
	PrintQueue();

	while(!QueueEmpty()) {
	dequeue(&item);
	}
	//dequeue(&item);
	printf("Queue after deleting :\n");
	PrintQueue();
	
	return 0;
}



