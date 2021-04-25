#include <stdio.h>

int A[50];
int N;

void subset1(int n)
{
	int i,j;

	for (i=0; i<(1<<n); i++) {
		for (j=0; j<n; j++) {
			if (i & (1 << j))
				printf("%d  ", A[j]);
		}
		printf("\n");
	}
}

void subset(int n)
{
	int i;

	if (n == 0) {
		//printf("%d  ", A[n]);
		//printf("\n");
		return;
	}
	for (i=0; i<n; i++) {
		printf("%d  ", A[i]);
	}
	printf("\n");
	subset(n-1);
}

int main()
{
	int i;
	int n;

	scanf("%d", &n);
	N = n;
	for (i=0; i<n; i++)
		A[i] = i+1;
	subset(n);

	return 0;
}
