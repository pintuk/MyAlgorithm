#include <stdio.h>

int N;
int L;
int Table[50000][10];

#define SWAP(a,b)	do { \
				int t = a; \
				a = b; \
				b = t; \
			} while(0)

void store(int *A)
{
	int i;

	for (i=1; i<=N; i++)
		Table[L][i] = A[i];

	L++;
}

void permute(int *A, int n)
{
	int i;

	if (n == N) {
		store(A);
		return;
	}
	for (i=n; i<=N; i++) {
		SWAP(A[n], A[i]);
		permute(A, n+1);
		SWAP(A[n], A[i]);
	}
}

int main()
{
	int i,j;
	int A[10];
	
	printf("Enter the number: ");
	scanf("%d", &N);

	for (i=1; i<=N; i++)
		A[i] = i;

	L = 0;
	permute(A, 1);
	printf("L = %d\n", L);
	for (i=0; i<L; i++) {
		for (j=1; j<=N; j++) {
			printf("%d   ", Table[i][j]);
		}
		printf("\n");
	}

	return 0;
}
