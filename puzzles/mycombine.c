#include <stdio.h>

int N;
int L;
int Table[50000][10];
int Array[10];

void store(int *A)
{
	int i;

	for (i=0; i<N; i++) {
		if (A[i] == 1)
			Table[L][i] = Array[i];
		//else
		//	Table[L][i] = 0;
	}

	L++;
}

void combine(int *A, int k)
{
	int i;

	if (k == N) {
		store(A);
		return;
	}
	A[k] = 0;
	combine(A, k+1);
	A[k] = 1;
	combine(A, k+1);
	//A[k] = 0;
}

int main()
{
	int i,j;
	int A[10];
	
	printf("Enter the number: ");
	scanf("%d", &N);

	for (i=0; i<N; i++)
		Array[i] = i+1;

	L = 0;
	combine(A, 0);
	printf("L = %d\n", L);
	for (i=0; i<L; i++) {
		for (j=0; j<N; j++) {
			//if (Table[i][j] == 0) continue;
			printf("%d   ", Table[i][j]);
		}
		printf("\n");
	}

	return 0;
}
