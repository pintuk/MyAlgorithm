#include <stdio.h>

#define INFINITY	9999999

int N;
int min = INFINITY;
int visited[100];

struct tyre_pressure {
	int inflate;
	int deflate;
} tyre[100];


void solve(int n, int value)
{
	int i;

	if (n == N-1) {
		if (value < min)
			min = value;
		printf("min value = %d\n", value);
		return;
	}
	printf("n: %d, value: %d\n", n, value);
	for (i=0; i<N; i++) {
		if (value + tyre[i].inflate <= 100 && ((value + tyre[i].inflate) - tyre[i].deflate) >= 0 && !visited[i]) {
			value = (value + tyre[i].inflate) - tyre[i].deflate;
			visited[i] = 1;
			solve(n+1, value);
			visited[i] = 0;
		}
	}
}

int main()
{
	int i;
	int t,T;

	scanf("%d", &T);
	for (t=1; t<= T; t++) {
		scanf("%d", &N);
		for (i=0; i<N; i++) {
			scanf("%d", &tyre[i].inflate);
		}
		for (i=0; i<N; i++) {
			scanf("%d", &tyre[i].deflate);
			visited[i] = 0;
		}
		min = INFINITY;
		solve(0,0);
		printf("Case #%d: %d\n", t, min);
	}
	return 0;
}
