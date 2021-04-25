#include <stdio.h>

#define MIN(a,b)	((a < b) ? (a) : (b))

int N,K;
int B[50];
int leftvalue = 0;


void PrintB(int Z)
{
	int i;

	printf("Value Z: %d\n", Z);
	for (i=1; i<=Z; i++) {
		printf("%d ", B[i]);
	}
	printf("\n");
}

int count_balloon()
{
	int i;
	int count = 0;

	for (i=1; i<=N; i++) {
		if (B[i] != 0)
			count++;
	}
	return count;
}

int solve(int N)
{
	int ret = 0;
	int a,b,c;
	int i,j;

	if (N < 3)
		return N;

	if (N == 3) {
		if ( ((B[2] - B[1]) == K) && ((B[3] - B[2]) == K) ) {
			B[1] = B[2] = B[3] = 0;
			return 0;
		}
		else {
			return 3;
		}
	}

	PrintB(N);
	leftvalue = count_balloon();

	for (i=3; i<=N; i++) {
		a = B[i-2];
		if (a == 0)
			continue;
	for (j=3; j<=N; j++) {
		b = B[i-1];
		if (b == 0)
			continue;
		a = B[i-2];
		if (a == 0)
			continue;

		//leftvalue = count_balloon();

		if ( ((b - a) == K) && ((c - b) == K) ) {
			B[i] = B[i-1] = B[i-2] = 0;
			leftvalue = leftvalue - 3;
			//solve(N-3);
			//solve(N-3);
		}
	}
	}
	
	return leftvalue;
}


int main()
{
	int t,T;

	setbuf(stdout, NULL);

	scanf("%d", &T);

	for (t=1; t<=T; t++) {
		int i = 0;
		int Answer = 0;

		scanf("%d %d", &N, &K);
		for (i=1; i<=N; i++) {
			scanf("%d", &B[i]);
		}
		Answer = solve(N);
		printf("#%d %d\n", t,Answer);
	}

	return 0;
}
