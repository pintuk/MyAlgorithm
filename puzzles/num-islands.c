#include <stdio.h>

int N,M;
int Grid[100][100];
int visited[100][100];


int issafe(int x, int y)
{
	if (x > 0 && x <=M && y > 0 && y <= N && Grid[x][y] == 1)
		return 1;

	return 0;
}

void dfs(int x, int y)
{
	
}
