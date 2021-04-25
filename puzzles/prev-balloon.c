#include <stdio.h>

#define MAX(a,b)	(((a) > (b)) ? (a) : (b))

int N;

int count(int *b, int *index1, int *index2)
{
	int i;
	int c = 0;
	
	*index1 = 0;
	*index2 = 0;
	for (i=1; i<=N; i++) {
		if (b[i] == 0)
			continue;
		c++;
		if (c == 1)
			*index1 = i;
		if (c == 2)
			*index2 = i;
	}
	return c;
}

int copy_array(int *temp, int *b, int x)
{
	int i;
	int k = 1;

	for (i=1; i<=N; i++) {
		if (i == x)
			continue;
		temp[k++] = b[i];
	}
	return k;
}

int PrintArray(int n, int *A)
{
	int i;

	for (i=1; i<=n; i++) {
		printf("%5d ", A[i]);
	}
	printf("\n");
}

int burst(int *b)
{
	int i;
	int C = 0;
	int max = 0;
	int index1,index2;
	int A[100];
	int temp[100];

	C = count(b, &index1, &index2);
	printf("Count = %d, index1: %d, index2: %d\n", C, index1, index2);
	
	if (C == 0)
		return 0;
	if (C == 1) {
		max = b[index1];
		//b[index1] = 0;
		return max;
	}
	if (C == 2) {
		max = MAX(b[index1], b[index2]) * 2;
		//b[index1] = b[index2] = 0;
		return max;
	}
	for (i=0; i<=N; i++)
		A[i] = 0;
	
	for (i=1; i<=C; i++) {
		temp[0] = temp[C+1] = 1;
		copy_array(temp, b);
		PrintArray(N, b);
		temp[i] = 0;
		PrintArray(N, temp);
		A[i] = MAX(A[i-1], temp[i-1]*temp[i+1] + burst(temp));
		//b[i] = 0;
	}
/*
	for (i=1; i<=N; i++) {
		C = count(b, &index1, &index2);
		for (j=1; j<=C; j++) {
		}
	}
*/
	return A[C];
}

int main()
{
	int i;
	int b[100];
	int Answer = 0;

	scanf("%d", &N);
	for (i=1; i<=N; i++)
		scanf("%d", &b[i]);
	b[0] = 1;
	b[N+1] = 1;

	Answer = burst(b);

	printf("%d\n", Answer);

	return 0;
}
