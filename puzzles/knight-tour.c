#include <stdio.h>

#define N	8

int sol[N][N];
int move = 0;
int movex[] = {2, 1,  1,  2, -2, -1, -1, -2};
int movey[] = {1, 2, -2, -1,  1,  2, -2, -1};

//int movex[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
//int movey[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

void PrintSolution()
{
	int i,j;

	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			printf("%2d ", sol[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int isSafe(int x, int y)
{
	if (((x >= 0 && x < N) && (y >=0 && y < N)) && (sol[x][y] == -1))
		return 1;
	else
		return 0;
}

int solveKT(int x, int y)
{
	int k;
	int v = 0;

	if (move >= N*N)
		return 1;

	for (k=0; k<8; k++) {
		int nx,ny;

		nx = x + movex[k];
		ny = y + movey[k];
		
		if (isSafe(nx, ny)) {
			sol[nx][ny] = move++;
			v = solveKT(nx, ny);
			if (v == 1) {
				return 1;
			} else {
				sol[nx][ny] = -1;
				move--;
			}
		}
	}

	return 0;
}

int solve()
{
	int i,j;
	int v = 0;
	//initialize sol matrix
	for (i=0; i<N; i++)
		for (j=0; j<N; j++)
			sol[i][j] = -1;

	sol[0][0] = 0;
	move = 1;

	v = solveKT(0, 0);
	if (v == 0) {
		printf("No solution....\n");
		return;
	} else {
		printf("SOLUTION FOUND:\n");
		PrintSolution();
	}
}


int main()
{
	solve();

	return 0;
}
