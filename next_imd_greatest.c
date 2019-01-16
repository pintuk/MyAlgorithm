#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE	100

int N;
int A[100005];
int B[100005];

int top;
struct Stack {
	int i;
	int item;
} stack[MAXSIZE];


void push(struct Stack tmp)
{
	top++;

	if (top >= MAXSIZE)
		return;

	stack[top].i = tmp.i;
	stack[top].item = tmp.item;
}

struct Stack pop(void)
{
	static struct Stack tmp = {-1, -1};

	if (top < 0)
		return tmp;

	tmp.i = stack[top].i;
	tmp.item = stack[top].item;
	top--;

	return tmp;
}

int isempty()
{
	if (top < 0)
		return 1;

	return 0;
}

void next_immediate_greatest(void)
{
	int i;
	struct Stack tmp = {-1, -1};

	top = -1;
	for (i = 0; i < N; i++) {
		B[i] = -1;
	}

	for (i = 0; i < N; i++) {
		if (isempty() || stack[top].item >= A[i]) {
			tmp.i = i;
			tmp.item = A[i];
			push(tmp);
		} else {
			while (!isempty() && stack[top].item < A[i]) {
				tmp = pop();
				B[tmp.i] = A[i];
				//printf("tmp.i: %d, tmp.item: %d\n", tmp.i, tmp.item);
			}
			tmp.i = i;
			tmp.item = A[i];
			push(tmp);
		}
	}
}

int main()
{
	int i;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);

	next_immediate_greatest();

	for (i = 0; i < N; i++) {
		printf("%d ", B[i]);
	}
	printf("\n");

	return 0;
}
