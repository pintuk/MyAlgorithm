#include <stdio.h>

int N;
int A[20];


repeatset(int n)
{
	int i;

	if (n == 0) {
		for (i=1; i<=N; i++)
			printf("%d  ", A[i]);
		printf("\n");
		return 0;
	}
	for (i=1; i<=N; i++) {
		A[n] = i;
		repeatset(n-1);
		//A[n] = 0;
	}
}


int main()
{
	scanf("%d", &N);
	repeatset(N);

	return 0;
}
