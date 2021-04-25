#include <stdio.h>

#define MAX(a,b)	((a) > (b) ? (a) : (b))

int N;
int Amount;
int profit[501][101];
int output[501];

void reset()
{
	int i,j;

	for (i=0; i<=500; i++)
		for (j=0; j<=100; j++) {
			profit[i][j] = 0;
			output[j] = 0;
		}
}

int solve()
{
	int i,j;
	
	for (i=Amount; i>0; i--) {
		for (j=1; j<=Amount; j++) {
			output[] = MAX(output[], profit[i][j]);
		}
	}
}

int main()
{
	int i,j;
	int A;
	int Answer = 0;

	scanf("%d %d", Amount, N);
	for (i=1; i<=Amount; i++) {
		scanf("%d", &A);
		for (j=1; j<=N; j++) {
			scanf("%d", &profit[i][j]);
		}
	}
	Answer = solve();
	printf("%d\n", Answer);

	return 0;
}
