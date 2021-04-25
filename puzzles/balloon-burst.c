#include <stdio.h>

#define MAX(a,b)	(((a) > (b)) ? (a) : (b))

int A[100];

int PrintArray(int n, int *A)
{
	int i;

	for (i=1; i<=n; i++) {
		printf("%5d ", A[i]);
	}
	printf("\n");
}

int copy_rest(int *temp, int *b, int N, int busted)
{
	int i;
	int k = 0;

	for (i=1; i<=N; i++) {
		/* if already busted dont include it */
		/* And copy rest ones only */
		if (i == busted)
			continue;
		temp[++k] = b[i];
	}
	return k;
}

int burst(int *b, int N)
{
	int i;
	int max = 0;

	if (N == 0)
		return 0;
	if (N == 1)
		return b[1];

	if (N == 2) {
		/* Maximum points we can get for 2 balloons, 
		 * is always, max balloon number x 2 */
		max = MAX(b[1], b[2]) * 2;
		return max;
	}

	max = 0;	
	for (i=1; i<=N; i++) {
		int C = 0;
		int temp[100] = {0,};

		b[0] = b[N+1] = 1;
		C = copy_rest(temp, b, N, i);
		max = MAX(max, b[i-1]*b[i+1] + burst(temp, C));
	}
	return A[N];
}

int main()
{
	int i;
	int N = 0;
	int b[100];
	int Answer = 0;

	scanf("%d", &N);
	for (i=1; i<=N; i++) {
		scanf("%d", &b[i]);
		A[i] = 0;
	}
	b[0] = 1;
	b[N+1] = 1;

	Answer = burst(b, N);

	printf("%d\n", Answer);

	return 0;
}
