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

#define QUEUE_SIZE	201
struct Queue {
	int x;
	int y;
	int dir;
	int count;
	int size;
} Q[201];

struct Queue queue;
int front = -1;
int rear = -1;

int insertQ(int x, int y, int dir, int count)
{
	rear++;
	Q[rear].x = x;
	Q[rear].y = y;
	Q[rear].dir = dir;
	Q[rear].count = count;
	queue.size++;

	return 0;
}

int removeQ(int *x, int *y, int *dir, int *count)
{
	*x = Q[rear].x;
	*y = Q[rear].y;
	*dir = Q[rear].dir;
	*count = Q[rear].count;
	front++;
	queue.size--;

	return 0;
}

int Qempty()
{
	if (queue.size == 0)
		return 1;

	return 0;
}

int solve(int x, int y, int dir, int count)
{
	int min = INFINITY;

	if (!issafe(x,y))
		return 0;

	visited[x][y] = 1;
	front = 1;
	rear = 0;
	insertQ(x,y,dir,count);
	while (!Qempty()) {
		int a,b;
		int px,py,pdir,pcount;
		int ret;

		removeQ(&px,&py,&pdir,&pcount);
		if (px == ex && py == ey) {
			if (pcount < min)
				min = pcount;
			break;
		}
	
		printf("px: %d, py: %d, pdir: %d, pcount: %d\n", px,py,pdir,pcount);
		//left
		a = px;
		b = py-1;
		if (issafe(a,b) && !visited[a][b]) {
			ret = (pdir==0 || pdir==1) ? insertQ(a,b,1,pcount) : insertQ(a,b,1,pcount+1);
			visited[a][b] = 1;
		}

		//right
		a = px;
		b = py+1;
		if (issafe(a,b) && !visited[a][b]) {
			ret = (pdir==0 || pdir==2) ? insertQ(a,b,2,pcount) : insertQ(a,b,2,pcount+1);
			visited[a][b] = 1;
		}

		//up
		a = px-1;
		b = py;
		if (issafe(a,b) && !visited[a][b]) {
			ret = (pdir==0 || pdir==3) ? insertQ(a,b,3,pcount) : insertQ(a,b,3,pcount+1);
			visited[a][b] = 1;
		}

		//down
		a = px+1;
		b = py;
		if (issafe(a,b) && !visited[a][b]) {
			ret = (pdir==0 || pdir==4) ? insertQ(a,b,4,pcount) : insertQ(a,b,4,pcount+1);
			visited[a][b] = 1;
		}

	}
	if (min == INFINITY)
		return -1;

	return min;
}

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
	queue.size = 0;
}

int main()
{
	int t,T;

	scanf("%d", &T);

	for (t=1; t<=T; t++) {
		int i,j;
		int Answer = -1;
		char robot[201];

		reset();
		memset(robot, 0, sizeof(robot));
		scanf("%d %d", &M, &N);
		scanf("%d %d %d %d", &sy,&sx,&ey,&ex);
		for (i=1; i<=N; i++) {
			scanf("%s", robot);
#if 1
			for (j=1; j<=M; j++) {
				if (robot[j-1] == '1')
					maze[i][j] = 1;
				else if (robot[j-1] == '0')
					maze[i][j] = 0;
				//scanf("%d", &maze[i][j]);
				visited[i][j] = 0;
				track[i][j] = INFINITY;
			}
#endif
		}
		mincount = INFINITY;
		Answer = solve(sx,sy,0,0);
		printf("%d\n", Answer);
	}
	return 0;
}

