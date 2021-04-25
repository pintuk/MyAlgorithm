#include <stdio.h>


#define INFINITY	0x7fffffff
#define MIN(a,b)	((a < b) ? (a) : (b))

int N;
int C[101][101];


int reset(int visited[], int index)
{
	int i;

	for (i=1; i<=3; i++) {
		if (i != index)
			visited[i] = 0;
	}
}

int solve_none()
{
	int i,j,k;
	int min = INFINITY;
	int cost = 0;
	int index = 0;
	int visited[101];
	int mincost = INFINITY;

	for (k=1; k<=3; k++) {
		index = 0;
		reset(visited,index);
		cost = C[1][k];

		visited[k] = 1;
		for (i=2; i<=N; i++) {
			min = INFINITY;
			index = 0;
			
			for (j=1; j<=3; j++) {
				if (C[i][j] < min && !visited[j]) {
					min = C[i][j];
					index = j;
				}
			}
			if (index > 0) {
				visited[index] = 1;
				reset(visited,index);
				cost = cost + min;
			}
		}
		//printf("cost = %d, mincost = %d\n", cost, mincost);
		if (cost < mincost)
			mincost = cost;
	}
	return mincost;
}

int minvalue = INFINITY;
int K[101][101];

int solve(int N, int color, int cost)
{
	int i;
	int ret;

	if (N == 0 || color == 0)
		return cost;

	//if (K[N][color] != INFINITY)
	//	return K[N][color];

	cost = cost + C[N][color];
	for (i=1; i<=3; i++) {
		if (i != color) {
			//ret = solve(N-1,i,cost);
			minvalue = MIN(minvalue, solve(N-1,i,cost));
			//K[N][color] = MIN(K[N][color], solve(N-1,i,cost));
			//if (ret < minvalue)
			//	minvalue = ret;
		}
	}
	return minvalue;
}

void PrintTable(int N)
{
	int i,j;

	for (i=0; i<=N; i++) {
		for (j=0; j<=3; j++) {
			printf("%d \t", K[i][j]);
		}
		printf("\n");
	}
}

int solve_DP(int N, int M)
{
	int i,j,k;

	for (i=0; i<=N; i++) {
		K[i][0] = 0;
		K[0][i] = 0;
	}

	for (i=1; i<=N; i++) {
		for (j=1; j<=M; j++) {
			for (k=1; k<=M; k++) {
				if (k != j)
					K[i][j] = MIN(K[i][j], K[i-1][k]) + C[i][j];
			}
		}
		printf("---------------------------------------\n");
		PrintTable(N);
	}

	return K[N][M];
}

#define USE_RECURSION 0

int main()
{
	int t,T;

	setbuf(stdout, NULL);

	scanf("%d", &T);

	for (t=1; t<=T; t++) {
		int i,j;
		int ret = 0;
		int a,b,c;
		int Answer = INFINITY;

		scanf("%d", &N);

		for (i=1; i<=N; i++) {
			for (j=1; j<=3; j++) {
				scanf("%d", &C[i][j]);
				K[i][j] = INFINITY;
			}
		}
		//ret = solve_none();
#if USE_RECURSION
		minvalue = INFINITY;
		for (i=1; i<=3; i++) {
			ret = solve(N,i,0);
			if (ret < Answer)
				Answer = ret;
		}
#endif
		Answer = solve_DP(N,3);
		printf("Case #%d\n", t);
		printf("%d\n", Answer);
	}

	return 0;
}

