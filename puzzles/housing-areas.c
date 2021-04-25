#include <stdio.h>


int N;
int house[1001][1001];
int visited[1001][1001];

int issafe(int x, int y)
{
	if ( (x > 0) && (x <= N) && (y > 0) && (y <= N) && house[x][y] == 1)
		return 1;

	return 0;
}

int find_house(int x, int y)
{
	int value = 0;

	if (!issafe(x, y))
		return 0;

	if (visited[x][y] == 1)
		return 0;

	visited[x][y] = 1;

	value = find_house(x, y-1);
	value |= find_house(x, y+1);
	value |= find_house(x-1, y);
	value |= find_house(x+1, y);

	return 1;
}

int solve()
{
	int i,j;
	int count = 0;

	for (i=1; i<=N; i++) {
		for (j=1; j<=N; j++) {
			if (find_house(i,j) == 1)
				count++;
		}
	}
	return count;
}

int main()
{
	int i,j,t,ncases;
	int num = 0;

	scanf("%d", &ncases);
	for (t=1; t<=ncases; t++) {
		scanf("%d", &N);
		for (i=1; i<=N; i++) {
			for (j=1; j<=N; j++) {
				scanf("%d", &house[i][j]);
				visited[i][j] = 0;
			}
		}
		num = solve();
		printf("%d\n", num);
	}
}

