#include<stdio.h>

#define INFINITY	9999999

int N,M;
int Map[100][100];
int visited[100][100];
int mincount = INFINITY;

enum Town {
	FENCE=1,
	DEAD=2,
	NORTH_SOUTH=3,
	EAST_WEST=4,
	HOME=8,
	SHOP=9
};

enum DIR {
	EAST=0,
	WEST,
	NORTH,
	SOUTH
};

int issafe(int x, int y)
{
	if (x > 0 && x <= N && y > 0 && y <= M)
		return 1;

	return 0;
}

void dfs(int x, int y, int dir, int count)
{
	int i;
	int dx[] = {-1,1,0,0};
	int dy[] = {0,0,-1,1};

	if (Map[x][y] == SHOP) {
		if (count < mincount)
			mincount = count;
		return;
	}

	printf("x: %d, y: %d, dir: %d, count: %d\n", x,y,dir,count);
	visited[x][y] = 1;
	for (i=0; i<4; i++) {
		int a = x + dx[i];
		int b = y + dy[i];

		if (issafe(a,b) && !visited[a][b]) {
			if (dx[i] == -1)
				dir = SOUTH;
			if (dx[i] == 1)
				dir = NORTH;
			if (dy[i] == -1)
				dir = WEST;
			if (dy[i] == 1)
				dir = EAST;
			if (Map[a][b] == FENCE || Map[a][b] == DEAD)
				continue;
			if (Map[a][b] == EAST_WEST && (dir == EAST || dir == WEST))
				continue;
			if (Map[a][b] == NORTH_SOUTH && (dir == NORTH || dir == SOUTH))
				continue;
			if (Map[a][b] == EAST_WEST && Map[x][y] != EAST_WEST && (dir == NORTH || dir == SOUTH))
				count++;
			if (Map[a][b] == NORTH_SOUTH && Map[x][y] != NORTH_SOUTH && (dir == EAST || dir == WEST))
				count++;

			dfs(a,b,dir,count);
		}
	}
	visited[x][y] = 0;
}

int solve(int x, int y)
{
	int minval = INFINITY;

	mincount = INFINITY;
	dfs(x,y,-1,0);
	if (mincount < minval)
		minval = mincount;

	if (minval == INFINITY)
		minval = -1;
	else
		minval = 1000 - minval;

	return minval;
}

int main()
{
	int t,T;

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (t=1; t<=T; t++) {
		int i,j;
		int Answer = -1;
		int x,y;

		scanf("%d %d", &N, &M);
		for (i=1; i<=N; i++) {
			for (j=1; j<=M; j++) {
				scanf("%d", &Map[i][j]);
				if (Map[i][j] == HOME) {
					x = i;
					y = j;
				}
			}
		}
		Answer = solve(x,y);
		printf("Case #%d\n%d\n", t, Answer);
	}

	return 0;
}
