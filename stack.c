#include <stdio.h>

#define MAXSIZE	50

int stack[MAXSIZE];
int top = -1;


void push(int item)
{
	if (top == MAXSIZE - 1) {
		printf("Error: stack overflow...\n");
		return;
	}
	top++;
	stack[top] = item;
}

int pop(void)
{
	int item;
	if (top == -1) {
		printf("Error: stack is empty...\n");
		return -1;
	}
	item = stack[top];
	top--;
	return item;
}

int isempty(void)
{
	if (top < 0)
		return 1;

	return 0;
}

int main()
{
	int i, N, A[10];

	top = -1;
	printf("Enter number of items: ");
	scanf("%d", &N);
	printf("Enter the items: \n");
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);

	for (i = 0; i < N; i++)
		push(A[i]);

	printf("The stack contents are:\n");
	while (!isempty()) {
		int s;

		s = pop();
		printf("%d\n", s);
	}

	return 0;
}
