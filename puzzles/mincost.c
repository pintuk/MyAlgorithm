#include <stdio.h>

#define MIN(a,b)	( ((a) < (b)) ? (a) : (b) )
#define INFINITY	((1 << 31) - 1)

int cost[100][100];
int M[100][100];


int mincost(int m, int n)
{
	if (m < 0 || n < 0)
		return INFINITY;
	if (m == 0 && n == 0)
		return cost[0][0];
	if (M[m][n] != INFINITY)
		return M[m][n];
	M[m][n] = cost[m][n] + MIN(MIN(mincost(m-1,n),mincost(m,n-1)), mincost(m-1,n-1));

	return M[m][n];
}

PrintTable(int m, int n, int Table[][100])
{
	int i,j;

	for (i=0; i<m; i++) {
		for (j=0; j<n; j++) {
			printf("%d  ", Table[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int i,j;
	int m,n;
	int answer = -1;

	scanf("%d %d", &m, &n);
	for (i=0; i<m; i++)
		for (j=0; j<n; j++) {
			scanf("%d", &cost[i][j]);
			M[i][j] = INFINITY;
		}
	M[0][0] = cost[0][0];
	//PrintTable(m,n);
	printf("Infinity: %d\n", INFINITY);
	answer = mincost(m-1,n-1);

	printf("Min Cost = %d\n", answer);

	return 0;
}

