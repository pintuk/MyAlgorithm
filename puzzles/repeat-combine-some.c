#include <stdio.h>

int N,K;
int A[100];


void Print(int *A)
{
	int i;
	for (i=0; i<K; i++) {
		printf("%d  ", A[i]);
	}
	printf("\n");
}

void choose(int k, int prev)
{
	int i;
	int temp;

	if (k == K) {
		Print(A);
		//printf("==========================\n");
		return;
	}
	temp = prev;
	for (i=1; i<=N; i++) {
		if (prev == i)
			continue;
		//printf("k: %d, prev: %d, i: %d\n", k,prev,i);
		A[k] = i;
		prev = i;
		choose(k+1,prev);
		prev = temp;
	}
}

int main()
{
	scanf("%d %d", &N, &K);
	choose(0,0);

	return 0;
}

