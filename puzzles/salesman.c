#include <stdio.h>

int rect[101][101];
int visited[101][101];
int N,M;
int count;
int s1,s2,s3,s4;

#define MAX(a,b)	(((a) > (b)) ? (a) : (b)) 

void PrintGrid()
{
	int i,j;

	printf("Row: %d, Col: %d\n", N,M);
	for (i=1; i<=N; i++) {
		for (j=1; j<=M; j++) {
			printf("%d\t ", rect[i][j]);
		}
		printf("\n");
	}
}

int issafe(int x, int y)
{
	if ((x > 0) && (x <= N) && (y > 0) && (y <= M) && rect[x][y])
		return 1;

	return 0;
}

int solve(int x, int y, int C)
{
	int value = 0;
	int s = 0;

	if (!issafe(x,y))
		return 0;

	if (visited[x][y])
		return -1;

	visited[x][y] = 1;

	value = rect[x][y];

	s = solve(x, y-value, C+1);
	if (s == -1)
		return -1;
	else
		s1 = C+1;
	s = solve(x, y+value, C+1);
	if (s == -1)
		return -1;
	else
		s2 = C+1;
	s = solve(x-value, y, C+1);
	if (s == -1)
		return -1;
	else
		s3 = C+1;
	s = solve(x+value, y, C+1);
	if (s == -1)
		return -1;
	else
		s4 = C+1;

	//printf("s: %d, s1: %d, s2: %d, s3: %d, s4: %d\n", s,s1,s2,s3,s4);

	count = MAX(count, (MAX(s1,s2), MAX(s3,s4)));
	
	return 1;
}

void reset()
{
	int i,j;

	for (i=1; i<=N; i++) {
		for (j=1; j<=M; j++) {
			visited[i][j] = 0;
		}
	}
	s1 = s2 = s3 = s4 = 0;
	count = 0;
}

int main()
{
	int t, ncases;

	scanf("%d", &ncases);
	for (t=1; t<=ncases; t++) {
		int i,j,k;
		char customer[100] = {0,};
		int ret = 0;
		scanf("%d", &N);
		for (i=1; i<=N; i++) {
			j=1;
			scanf("%s", customer);
			for (k=0; customer[k]!= '\0'; k++) {
				rect[i][j++] = customer[k] - '0';
				visited[i][j] = 0;
			}
			M = j-1;
		}
		reset();
		//PrintGrid();
		s1 = s2 = s3 = s4 = 0;
		count = 0;
		ret = solve(1,1,0);
		if (ret == -1)
			printf("%d\n", ret);
		else
			printf("%d\n", count);
	}
	return 0;
}

