#include <stdio.h>


#define MAX(a,b)	((a > b) ? (a) : (b))

int N;
int maze[1001][1001];
int K[1001][1001];

int issafe(int x, int y)
{
	if ( ((x > 0) && (x <= N)) && ((y > 0) && (y <= N)))
		return 1;
	else
		return 0;
}

void PrintPath()
{
	int i,j;

	for (i=1; i<=N; i++) {
		for (j=1; j<=N; j++) {
			printf("%d ", K[i][j]);
		}
		printf("\n");
	}
}


int solve()
{
	int i,j;

	for (i=0; i<=N+1; i++) {
		K[i][0] = 0;
		K[0][i] = 0;
	}

	for (i=1; i<=N; i++) {
		for (j=1; j<=N; j++) {
			K[i][j] = maze[i][j] + MAX(K[i][j-1], K[i-1][j]);
		}
	}
	return K[N][N];
}

int main()
{
	int t,T;

	setbuf(stdout, NULL);

	scanf("%d", &T);

	for (t=1; t<=T; t++) {
		int i,j;
		int ret = 0;

		scanf("%d", &N);
		for (i=1; i<=N; i++) {
			for (j=1; j<=N; j++) {
				scanf("%d", &maze[i][j]);
				K[i][j] = 0;
			}
		}
		ret = solve();
		printf("%d\n", ret);
		//printf("%d\n", visited[N][N]);
		printf("path:----->\n");
		PrintPath();
	}

	return 0;
}

