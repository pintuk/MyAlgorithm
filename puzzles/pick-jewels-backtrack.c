#include <stdio.h>

#define INFINITY        0x7fffffff

int maze[101][101];
int N;
int sx,sy,ex,ey;
int maxvalue = -1;
int visited[101][101];
int track[101][101];
int count = 0;


int issafe(int x, int y)
{
        if (x > 0 && x <= N && y > 0 && y <= N && (maze[x][y] != 1))
                return 1;
        return 0;
}


void PrintMaze(int A[][101])
{
	int i,j;

	for (i=1; i<=N; i++) {
		for (j=1; j<=N; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
}

void save_path(int dest[][101], int src[][101])
{
	int i,j;

	for (i=1; i<=N; i++)
		for (j=1; j<=N; j++)
			dest[i][j] = src[i][j];
}

int solve(int x, int y)
{
	int ret = 0;
	int prev = 0;

	if (!issafe(x,y))
		return 0;

	if (visited[x][y] == 1)
		return 0;

	visited[x][y] = 1;

        if (x == N && y == N) {
		if (maze[x][y] == 2)
			count++;
		//maze[x][y] = 3;
                if (count > maxvalue) {
			maxvalue = count;
			save_path(track, maze);
		}
                return 1;
        }

	//if (visited[x][y] == 1)
	//	return 0;
	//visited[x][y] = 1;

	//if (maze[x][y] == 3)
	//	return 0;

	if (maze[x][y] == 2)
		count++;
	//prev = maze[x][y];
	//maze[x][y] = 3;

	ret = solve(x, y-1);
	if (ret == 1)
		return 1;
	ret = solve(x, y+1);
	if (ret == 1)
		return 1;
	ret = solve(x-1, y);
	if (ret == 1)
		return 1;
	ret = solve(x+1, y);
	if (ret == 1)
		return 1;

	visited[x][y] = 0;
	maze[x][y] = prev;
	if (maze[x][y] == 2)
		count--;


	return 0;
}


int main()
{
	int t,T;

	//freopen("sample_input_jewels.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (t=1; t<=T; t++) {
		int i,j;
		int ret = 0;

		scanf("%d", &N);
		for (i=1; i<=N; i++) {
			for (j=1; j<=N; j++) {
				scanf("%d", &maze[i][j]);
				visited[i][j] = 0;
				track[i][j] = maze[i][j];
			}
		}
		maxvalue = 0;
		ret = solve(1,1);
		printf("Case #%d\n", t);
		if (ret == 1) {
			PrintMaze(track);
			printf("%d\n", maxvalue);
		}
		else
			printf("-1\n");
		printf("visited arrary:\n");
		PrintMaze(visited);
	}

	return 0;
}

