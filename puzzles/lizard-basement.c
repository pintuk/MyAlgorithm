#include <stdio.h>

#define MAX(a,b)	((a) > (b) ? (a) : (b))
#define MIN(a,b)	((a) < (b) ? (a) : (b))

int N;
int a,b;
int point[100];


int solve(int N)
{
	if (N == 0) return 0;
	if (N == 1) {
		int value = 0;

		value = point[N]/a + 1;
		return value;
	}

	
}

int main()
{
	int i;
	int Answer = 0;

	scanf("%d %d %d\n", N,a,b);
	for (i=1; i<=N; i++) {
		scanf("%d", &point[i]);
	}
	Answer = solve(N);

	printf("Answer = %d\n", Answer);

	return 0;
}
