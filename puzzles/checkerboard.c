#include <stdio.h>

#define MIN(a,b)	(((a) < (b)) ? (a) : (b))
#define INFINITY        999999


int N,M;
int Grid[1001][1001];
int minvalue = INFINITY;
int T[1001][1001];
int store[1001];
int k = 0;

int issafe(int x, int y)
{
        if ((x > 0 && x <= N) && (y > 0 && y <= M) && (Grid[x][y]))
                return 1;

        return 0;
}

void PrintTable()
{
	int i,j;

	printf("----------------------------------------\n");
	for (i=1; i<=N; i++) {
		for (j=1; j<=M; j++) {
			printf("%8d ", T[i][j]);
		}
		printf("\n\n");
	}
	printf("----------------------------------------\n");
}

int solve(int row, int col)
{
	int j = 0;
	int A1,A2,A3;

	if (!issafe(row, col))
		return INFINITY;

	if (row == 1) {
		//store[k++] = col;
		return Grid[row][col];
	}

	if (T[row][col] != INFINITY) {
		//store[k++] = col;
		return T[row][col];
	}

	store[0] = col;

	//T[row][col] = Grid[row][col] + MIN(solve(row-1,col-1), MIN(solve(row-1,col),solve(row-1,col+1)));
	A1 = solve(row-1,col-1);
	A2 = solve(row-1,col);
	A3 = solve(row-1,col+1);

	if (A2 < A3) {
		minvalue = A2;
		store[k] = col;
	} else {
		minvalue = A2;
		store[k] = col+1;
	}
	if (A1 < minvalue) {
		minvalue = A1;
		store[k] = col-1;
	}
	k++;
	T[row][col] = Grid[row][col] + minvalue;
	PrintTable();

	store[k++] = col;

	return T[row][col];
}

int reset()
{
	int i,j;

	for (i=0; i<=N; i++) {
		for (j=0; j<=M; j++) {
			T[i][j] = INFINITY;
		}
		store[i] = 0;
	}
}

int reset_data()
{
	int i;

	for (i=0; i<=M; i++)
		store[i] = 0;
}

int main()
{
	int i,j;
	int min = INFINITY;
	scanf("%d %d", &N, &M);

	reset();
	for (i=1; i<=N; i++)
		for (j=1; j<=M; j++)
			scanf("%d", &Grid[i][j]);
	for (i=1; i<=M; i++) {
		int val = 0;
		printf("=======================\n");
		reset_data();
		k = 1;
		val = solve(N, i);
		//min = MIN(min, solve(N, i));
		if (val < min) {
			min = val;
			//store[0] = i;
		}
	}

	printf("Min cost = %d\n", min);
	for (i=0; i<=k; i++)
		printf("%5d ", store[i]);
	printf("\n");

	return 0;
}
