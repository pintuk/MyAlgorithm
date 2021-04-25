#include <stdio.h>


#define MAX(a,b)	(((a) > (b)) ? (a) : (b))

int plane[100][100];


int issafe(int N, int Z, int x, int y)
{
	if (x >= Z && x <= N+1 && y > 0 && y <= 5)
		return 1;

	return 0;
}

int maxcount = -1;
int solve(int N, int Z, int x, int y, int count)
{
	int c1,c2,c3;
	int ret = -1;

	if (!issafe(N, Z, x, y))
		return 0;

	if (plane[x][y] == 2) {
		if (count <= 0)
			return -1;

		count--;
	} else if (plane[x][y] == 1) {
		count++;
	}
	//printf("x: %d, y: %d, count: %d\n", x,y,count);

	c1 = solve(N,Z,x-1,y-1,count);
	c2 = solve(N,Z,x-1,y,count);
	c3 = solve(N,Z,x-1,y+1,count);
	printf("c1: %d, c2: %d, c3: %d, count: %d\n", c1,c2,c3,count);
	//if (c1 == -1 && c2 == -1 && c3 == -1 && count == 0)
	//	count = -1;

	//ret = MAX(c1,MAX(c2,c3));
	if (count > maxcount)
		maxcount = count;

	return maxcount;
}

int blast_bomb(int N, int Z)
{
	int i,j;

	for (i=Z; i<=N; i++) {
		for (j=1; j<=5; j++) {
			if (plane[i][j] == 2)
				plane[i][j] = 0;
		}
	}
}

int collect_coins(int N)
{
	int i,j;
	int coins = 0;
	int maxcoins = -1;
	int flag = 0;

	for (j=N; j>=1; j=j-5) {
		int Z = 0;
		int count = 0;
		int middle = 3;
		int ret_nobomb = -1;
		int ret_withbomb = -1;
		int ret = -1;

		for (i=1; i<=5; i++)
			plane[j+1][i] = 0;
		Z = (j+1) - 5;
		if (Z < 0)
			Z = 1;
		maxcount = -1;
		ret_nobomb = solve(j,Z,j+1,middle,count);
		printf("ret_nobomb = %d\n", ret_nobomb);
		if (flag == 0) {
			blast_bomb(N,Z);
			maxcount = -1;
			count = 0;
			//middle = 3;
			ret_withbomb = solve(j,Z,j+1,middle,count);
			printf("ret_withbomb = %d\n", ret_withbomb);
		}
		if (ret_withbomb > ret_nobomb) {
			ret = ret_withbomb;
			flag = 1;
		}
		else
			ret = ret_nobomb;
		printf("ret = %d\n", ret);
		if (ret < 0)
			return -1;
		else
			coins += ret;
	}
	return coins;
}

int main()
{
	int i,j;
	int N;
	int Answer = -1;

	scanf("%d", &N);
	for (i=1; i<=N; i++) {
		for (j=1; j<=5; j++) {
			scanf("%d", &plane[i][j]);
		}
	}
	Answer = collect_coins(N);
	printf("%d\n", Answer);

	return 0;
}



