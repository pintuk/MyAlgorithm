#include <stdio.h>

#define QUEUE_SIZE	100

int front = -1;
int rear = -1;
int N=0;

struct Queue {
        int x;
        int y;
        int size;
} Q[101];

struct Queue queue = {0,0,0};

int Qempty()
{
        if(queue.size == 0) 
		return 1;
        else
        return 0;
}

void insertQ(int x, int y)
{
        rear = rear + 1;
        if(queue.size > QUEUE_SIZE)
                return;
        Q[rear].x = x;
        Q[rear].y = y;
	queue.size++;
}

int removeQ(int *x, int *y)
{
        if(queue.size <= 0) {
                return -1;
        }
        *x = Q[front].x;
        *y = Q[front].y;
        front = front + 1;
	queue.size--;
}

void PrintQ()
{
	int i;

	for (i=0; i<N; i++) {
		printf("[%d,%d] <- ", Q[i].x, Q[i].y);
	}
	printf("\n");
}

int main()
{
	int i;
	int px,py;

	scanf("%d", &N);
	front = 0;
	for (i=0; i<N; i++) {
		int a,b;

		scanf("%d %d", &a,&b);
		insertQ(a,b);
		printf("front = %d, rear = %d, size = %d\n", front, rear, queue.size);
	}
	while (!Qempty()) {
		printf("-------------------------------\n");
		PrintQ();
		removeQ(&px,&py);
		printf("remove x: %d, remove y: %d\n", px,py);
		printf("front = %d, rear = %d, size = %d\n", front, rear, queue.size);
	}
	return 0;
}



