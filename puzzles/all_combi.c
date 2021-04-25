// All Combinations.cpp : Defines the entry point for the console application.
//
#include <stdio.h>

#define N 5  // Number of options
#define R 3  // Number of options to select

int stack[100];  //Stack size can be based on business logic

int count = 0;

int visited[N + 1] = { 0 };

int L=0;
int Table[50000][10];

void store(int *A)
{
	int i;

	for (i=0; i<R; i++) {
		Table[L][i] = A[i];
	}
	L++;
}

void combine(int k)
{
	int i;
	if (k  == R)
	{
		store(stack);
		for (i = 0; i < R; i++)
			printf("%d\t", stack[i]);
		printf("\n");
		//printf("\t\tTotal = %d \n", total);
		count++;		
		return;
	}
	for (i = 1; i <= N; i++)
	{
		if (visited[i]) continue;
		stack[k] = i;

		visited[i] = 1;
		combine(k+1);
		visited[i] = 0;
	}
}


int main()
{
	int i,j;
	combine(0);
	printf("Select count = %d\n", count);

	for (i=0; i<L; i++) {
		for (j=0; j<R; j++) {
			printf("%d  ", Table[i][j]);
		}
		printf("\n");
	}
	printf("L = %d\n", L);

	return 0;
}
