#include <stdio.h>


#define INFINITY	999999

int N;
int sky[25][25];
int visited[25][25];
int sol[625];
int stars = 0;

void reset()
{
	int i,j;

	for (i=0; i<N; i++)
		for (j=0; j<N; j++)
			visited[i][j] = 0;
	for (i=0; i<N; i++)
		sol[i] = 0;
}

int issafe(int x, int y)
{
	if (x >= 0 && x < N && y >= 0 && y < N && sky[x][y] == 1)
		return 1;

	return 0;
}

int move(int x, int y)
{
	if (!issafe(x, y))
		return 0;
	if (visited[x][y])
		return 0;

	visited[x][y] = 1;
	//stars = 1;

	if (move(x-1, y) == 1)
		stars++;

	if (move(x+1, y) == 1)
		stars++;

	if (move(x, y-1) == 1)
		stars++;

	if (move(x, y+1) == 1)
		stars++;

	return 1;
}

void solve()
{
	int i,j;
	int k = 0;
	int maxstars = -INFINITY;

	stars = 0;
	reset();
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			stars = 1;
			if (move(i, j) == 1) {
				sol[k] = stars;
				if (sol[k] > maxstars)
					maxstars = sol[k];
				printf("value cons = %d\n", sol[k]);
				k++;
			}
		}
	}

	printf("No. of constellations = %d\n", k);
	printf("No. of stars in Big constellations = %d\n", maxstars);
}

int main()
{
	int i,j;

	scanf("%d", &N);
	for (i=0; i<N; i++)
		for (j=0; j<N; j++)
			scanf("%d", &sky[i][j]);

	solve();

	return 0;
}
