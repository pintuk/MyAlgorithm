#include <stdio.h>

int N,R;

int visited[1024];
int A[1024];
int L=0;
int Table[50000][1024];

#define SWAP(a,b)	do { \
				int t; \
				t = a; \
				a = b; \
				b = t; \
			} while (0)

void store(int *A, int N)
{
	int i;

	for (i=0; i<N; i++) {
		Table[L][i] = A[i];
	}

	L++;
}

void PrintTable(int N, int M)
{
	int i,j;

	for (i=0; i<N; i++) {
		for (j=0; j<M; j++) {
			printf("%d  ", Table[i][j]);
		}
		printf("\n");
	}
	printf("Total = %d\n", N);
}

void permute(int k)
{
	int i;

	if (k == N) {
		store(A, N);
		return;
	}
	for (i=k; i<N; i++) {
		SWAP(A[i], A[k]);
		permute(k+1);
		SWAP(A[i], A[k]);
	}
}

void combine(int k)
{
	int i;

	if (k == R) {
		store(A, R);
		return;
	}

	for (i=1; i<=N; i++) {
		if (visited[i]) continue;

		A[k] = i;
		visited[i] = 1;
		combine(k+1);
		visited[i] = 0;
	}
}

int main()
{
	int i;
	int choice;


	while (1) {
		printf("***** MENU ******\n");
		printf("1. All Permutation\n");
		printf("2. All combination\n");
		printf("3. Non repeat combination\n");
		printf("4. Once combination\n");

		printf("Enter the choice: ");
		scanf("%d", &choice);

		switch (choice) {

			case 1:

			printf("Enter value of N: ");
			scanf("%d", &N);

			for (i=1; i<=N; i++)
				A[i-1] = i;
			L = 0;
			permute(1);
			PrintTable(L, N);
		
			break;

			case 2:
			break;

			case 3:

			printf("Enter value of N & R: ");
			scanf("%d %d", &N, &R);
			L = 0;
			for (i=0; i<=N; i++)
				visited[i] = 0;
			combine(0);
			PrintTable(L, R);
			break;

			case 4:
			break;

		}
	}

	return 0;
}

