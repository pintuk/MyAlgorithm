#include <stdio.h>


int N;
int maze[1001][1001];
int visited[1001][1001];
int maxcount = 0;

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
			printf("%d ", visited[i][j]);
		}
		printf("\n");
	}
}

int solve(int x, int y, int count)
{
	int ret = 0;

	//if (count <= visited[x][y])
	//	return 0;

	if (x == N && y == N) {
		if (maze[x][y] == 1)
			count++;
		if (count > maxcount) {
			maxcount = count;
		}
		return 1;
	}

	if (!issafe(x,y))
		return 0;

	//visited[x][y] = 1;

	if (maze[x][y] == 1)
		count++;

	ret = solve(x,y+1,count);
	if (ret == 1)
		return 1;
	else {
		if (maze[x][y] == 1)
			count--;
	}
	ret = solve(x+1,y,count);
	if (ret == 1)
		return 1;
	else {
		if (maze[x][y] == 1)
			count--;
	}

	//visited[x][y] = 0;

	//if (maze[x][y] == 1)
	//	count--;

	//if (ret == 1)
	//	return 1;

	return 0;
}

int main()
{
	int t,T;

	setbuf(stdin, NULL);

	scanf("%d", &T);

	for (t=1; t<=T; t++) {
		int i,j;
		int ret = 0;

		scanf("%d", &N);
		for (i=1; i<=N; i++) {
			for (j=1; j<=N; j++) {
				scanf("%d", &maze[i][j]);
				visited[i][j] = 0;
			}
		}
		maxcount = 0;
		ret = solve(1,1,0);
		printf("%d\n", maxcount);
		//PrintPath();
	}

	return 0;
}





