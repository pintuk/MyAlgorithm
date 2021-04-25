#include <stdio.h>


int N;
int maze[1001][1001];
int visited[1001][1001];

#define QUEUE_SIZE	(1001 * 1001)

struct Queue {
	int x;
	int y;
	int count;
	int size;
} Q[QUEUE_SIZE+1];

struct Queue queue = {0,0,0,0};
int front = -1;
int rear = -1;

void insertQ(struct Queue *q)
{
	if (queue.size > QUEUE_SIZE)
		return;
	rear++;
	Q[rear].x = q->x;
	Q[rear].y = q->y;
	Q[rear].count = q->count;

	queue.size++;
}

void removeQ(struct Queue *q)
{
	if (queue.size <= 0)
		return;

	q->x = Q[front].x;
	q->y = Q[front].y;
	q->count = Q[front].count;

	front++;

	queue.size--;
}

int isQempty()
{
	if (queue.size <= 0)
		return 1;

	return 0;
}

int issafe(int x, int y)
{
	if ( ((x > 0) && (x <= N)) && ((y > 0) && (y <= N)))
		return 1;
	else
		return 0;
}

void PrintPath()
{
	int i,j;

	for (i=1; i<=N; i++) {
		for (j=1; j<=N; j++) {
			printf("%d ", visited[i][j]);
		}
		printf("\n");
	}
}

int solve(int x, int y, int count)
{
	int ret = 0;
	struct Queue q = {0,0,0,0};
	int maxcount = -1;

	if (!issafe(x,y))
		return -1;

	front = 1;
	rear = 0;

	q.x = x;
	q.y = y;
	q.count = count;
	queue.size = 0;
	insertQ(&q);
	visited[x][y] = 1;

	while (!isQempty()) {
		int rx,ry,rcount;
		int a,b;
		int i;
		int dx[] = {0,1};
		int dy[] = {1,0};

		removeQ(&q);
		rx = q.x;
		ry = q.y;
		rcount = q.count;

		printf("rcount = %d\n", rcount);

		if (rx == N && ry == N) {
			if (rcount > maxcount)
				maxcount = rcount;
			break;
		}

		for (i=0; i<2; i++) {
			a = rx + dx[i];
			b = ry + dy[i];
			//if (issafe(a,b) && !visited[a][b]) {
			if (issafe(a,b)) {
				visited[a][b] = 1;
				q.x = a;
				q.y = b;
				q.count = rcount;
				if (maze[a][b] == 1)
					q.count = rcount + 1;
				insertQ(&q);
			}
		}
	}

	return maxcount;
}

int main()
{
	int t,T;

	setbuf(stdout, NULL);

	scanf("%d", &T);

	for (t=1; t<=T; t++) {
		int i,j;
		int ret = 0;

		scanf("%d", &N);
		for (i=1; i<=N; i++) {
			for (j=1; j<=N; j++) {
				scanf("%d", &maze[i][j]);
				visited[i][j] = 0;
				Q[i].x = 0;
				Q[i].y = 0;
				Q[i].count = 0;
				Q[N+i].x = 0;
				Q[N+i].y = 0;
				Q[N+i].count = 0;
			}
		}
		ret = solve(1,1,0);
		printf("%d\n", ret);
		//printf("%d\n", visited[N][N]);
		//printf("path:----->\n");
		//PrintPath();
	}

	return 0;
}

