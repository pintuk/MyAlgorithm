#include <stdio.h>


#define	INFINITY	999999
#define MAX(a,b)	(((a) > (b)) ? (a) : (b))
#define QUEUE_SIZE	101

#define __BFS__		0
#define __DFS__		1

int N,M;
int city[101][101];
int visited[101][101];
int maxvalue = 0;

#if __BFS__
int Qx[101];
int Qy[101];
int front = -1;
int rear = -1;

struct Queue {
	int x;
	int y;
	int count;
	int size;
} Q[101];

struct Queue queue = {0,0,0};
#endif

int issafe(int x, int y)
{
	if ((x > 0 && x <= N) && (y > 0 && y <= M) && (city[x][y]))
		return 1;
	
	return 0;
}

#if __BFS__
int Qempty()
{
        if(queue.size == 0) 
		return 1;
        else
        return 0;
}

void insertQ(int x, int y, int count)
{
	rear = rear + 1;
	if(queue.size > QUEUE_SIZE)
		return;
	Q[rear].x = x;
	Q[rear].y = y;
	Q[rear].count = count;
	queue.size++;
}

int removeQ(int *x, int *y, int *count)
{
	if(queue.size <= 0) {
		return -1;
	}
	*x = Q[front].x;
	*y = Q[front].y;
	*count = Q[front].count;
	front = front + 1;
	queue.size--;
}

int solve(int x, int y)
{
	int px,py;
	int max = 0;

	front = 0;
	max = 1;
	insertQ(x, y, 1);
	visited[x][y] = 1;

	while (!Qempty()) {
		int ret;
		int px,py,count;
		int i,j;
		int a,b;
		int flag = 0;
		
		ret = removeQ(&px, &py, &count);

		//left
		a = px;
		b = py - 1;
		if (issafe(a, b) && !visited[a][b]) {
			insertQ(a,b,count+1);
			visited[a][b] = 1;
			city[a][b] = 0;
			flag = 1;
		}
		//right
		a = px;
		b = py + 1;
		if (issafe(a, b) && !visited[a][b]) {
			insertQ(a,b,count+1);
			visited[a][b] = 1;
			city[a][b] = 0;
			flag = 1;
		}
		//top
		a = px - 1;
		b = py;
		if (issafe(a, b) && !visited[a][b]) {
			insertQ(a,b,count+1);
			visited[a][b] = 1;
			city[a][b] = 0;
			flag = 1;
		}
		//down
		a = px + 1;
		b = py;
		if (issafe(a, b) && !visited[a][b]) {
			insertQ(a,b,count+1);
			visited[a][b] = 1;
			city[a][b] = 0;
			flag = 1;
		}
		if (flag == 1) {
			if ((count+1) > max)
				max = count+1;
		}
	}
	return max;
}
#endif

#if __DFS__
int solve(int x, int y, int count)
{
	int s;
	s = 0;

	if (!issafe(x,y))
		return 0;
	if (visited[x][y]) {
		return 0;
	}

	visited[x][y] = 1;
	//printf("A = %d, B = %d, count = %d\n", x,y,count);
	printf("--------------------------------\n");

	s = solve(x, y-1, count+1);
	s |= solve(x, y+1, count+1);
	s |= solve(x-1, y, count+1);
	s |= solve(x+1, y, count+1);
	printf("x = %d, y = %d :: s = %d\n", x, y, s);
	//if (s) 
	{
		if ((count+1) > maxvalue) {
			maxvalue = count+1;
			printf("maxvalue = %d\n", maxvalue);
		}
		return 1;
	}
	visited[x][y] = 0;

	return 0;
}
#endif

void reset()
{
	int i,j;

	for (i=0; i<=N; i++) {
		for (j=0; j<=M; j++) {
			city[i][j] = 0;
			visited[i][j] = 0;
		}
	}
	maxvalue = 0;
}

int main()
{
	int i,j;
	int bombi, bombj;
	int val = 0;

	scanf("%d %d", &M, &N);
	reset();
	for (i=1; i<=N; i++)
		for (j=1; j<=M; j++)
			scanf("%d ", &city[i][j]);
	scanf("%d %d", &bombj, &bombi);
#if __DFS__
	maxvalue = 1;
	val = solve(bombi, bombj, 1);
	printf("%d\n", maxvalue);
#endif
#if __BFS__
	val = solve(bombi, bombj);
	printf("%d\n", val);
#endif
	return 0;
}

