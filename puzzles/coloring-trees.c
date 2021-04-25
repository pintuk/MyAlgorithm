#include <stdio.h>

#define MIN(a,b)        ((a) < (b) ? (a) : (b))
#define INFINITY        (999999)

int N,M,K;
int C[101];
int P[101][101];

int unique_color(int C[])
{
	int i;
	int count = 1;
	int s = C[0];

	if (s == 0) return 0;
	for (i=1; i<M; i++) {
		if (C[i] == 0) return 0;
		if (C[i] != s) {
			count++;
			s = C[i];
		}
	}
	return count;
}

int solve(int i, int C[])
{
	int ans = INFINITY;
	int j;

	if (i == N) return 0;
	//if (C[i] != 0) return 0;

	if (unique_color(C) == K) return 0;
	if (unique_color(C) > K) return INFINITY;

	if (C[i] != 0) {
		ans = MIN(ans, solve(i+1, C));
	} else {
		for (j=0; j<M; j++) {
			C[i] = j;
			ans = MIN(ans, solve(i+1, C) + P[i][j]);
		}
	}
	return ans;
}

int main()
{
	int t,T;

	//freopen("input_trees.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);

	for (t=1; t<=T; t++) {
		int i,j;
		int Answer = 0;

		scanf("%d %d %d", &N, &M, &K);
		for (i=0; i<=M; i++) {
			scanf("%d", &C[i]);
		}
		for (i=0; i<N; i++) {
			for (j=0; j<M; j++) {
				scanf("%d", &P[i][j]);
			}
		}
		Answer = solve(0, C);
		if (Answer >= INFINITY) {
			Answer = -1;
			printf("#%d %d\n", t, Answer);
		}
		else
			printf("#%d %d\n", t, Answer);
	}

	return 0;
}

