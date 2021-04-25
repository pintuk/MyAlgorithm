#include <stdio.h>
#include <string.h>

#define INFINITY	0x7fffffff

int maze[201][201];
int N,M;
int sx,sy,ex,ey;
int mincount;
int visited[201][201];
int track[201][201];

int issafe(int x, int y)
{
	if (x > 0 && x <= N && y > 0 && y <= M && maze[x][y] == 0)
		return 1;
	return 0;
}

#if 1
int solve(int x, int y, int dir, int count)
{
	int ret;

	if (!issafe(x,y))
		return 0;

	//if (visited[x][y])
	//	return 0;

	if (track[x][y] <= count)
		return 0;
	track[x][y] = count;

	if (x == ex && y == ey) {
		if (count < mincount)
			mincount = count;
		return 1;
	}

	//visited[x][y] = 1;

	ret = (dir==0 || dir==1) ? solve(x,y+1,1,count) : solve(x,y+1,1,count+1);
	ret |= (dir==0 || dir==2) ? solve(x,y-1,2,count) : solve(x,y-1,2,count+1);
	ret |= (dir==0 || dir==3) ? solve(x-1,y,3,count) : solve(x-1,y,3,count+1);
	ret |= (dir==0 || dir==4) ? solve(x+1,y,4,count) : solve(x+1,y,4,count+1);


	//visited[x][y] = 0;
	//count--;

	if (ret == 1)
		return 1;

	return 0;
}
#endif

int reset()
{
	int i,j;

	for (i=1; i<=N; i++) {
		for (j=1; j<=M; j++) {
			maze[i][j] = 0;
			visited[i][j] = 0;
			track[i][j] = INFINITY;
		}
	}
}

int main()
{
	int t,T;

	scanf("%d", &T);

	for (t=1; t<=T; t++) {
		int i,j;
		int Answer = -1;
		char robot[201];

		memset(robot, 0, sizeof(robot));
		scanf("%d %d", &M, &N);
		scanf("%d %d %d %d", &sy,&sx,&ey,&ex);
		for (i=0; i<N; i++) {
			scanf("%s", robot);
#if 1
			for (j=1; j<=M; j++) {
				if (robot[j-1] == '1')
					maze[i][j] = 1;
				else if (robot[j-1] == '0')
					maze[i][j] = 0;
				visited[i][j] = 0;
				track[i][j] = INFINITY;
			}
#endif
		}
		mincount = INFINITY;
		Answer = solve(sx,sy,0,0);
		printf("%d\n", mincount);
		if (track[ex][ey] == INFINITY)
			printf("-1\n");
		else
			printf("%d\n", track[ex][ey]);
	}
	return 0;
}

