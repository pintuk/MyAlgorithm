#include <stdio.h>


#define	INFINITY	999999
#define MAX(a,b)	(((a) > (b)) ? (a) : (b))
#define QUEUE_SIZE	(101*101 + 2)

int N,M;
int city[101][101];
int visited[101][101];

int front = -1;
int rear = -1;

struct Queue {
	int x;
	int y;
	int count;
	int size;
} Q[QUEUE_SIZE];

struct Queue queue = {0,0,0,0};

int issafe(int x, int y)
{
	if ((x > 0 && x <= N) && (y > 0 && y <= M) && (city[x][y]))
		return 1;
	
	return 0;
}

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

	front = 1;
	rear = 0;
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

void reset(void)
{
	int i;

	front = -1;
	rear = -1;
	queue.size = 0;
	queue.count = 0;
	for (i=0; i<= QUEUE_SIZE; i++)
		Q[i].x = 0;
		Q[i].y = 0;
		Q[i].size = 0;
		Q[i].count = 0;
}

int main()
{
	int i,j,t,ncases;
	int bombi, bombj;
	int val = 0;

	scanf("%d", &ncases);
	for (t=1; t<=ncases; t++) {
		reset();
		scanf("%d %d", &M, &N);
		for (i=1; i<=N; i++) {
			for (j=1; j<=M; j++) {
				scanf("%d ", &city[i][j]);
				visited[i][j] = 0;
			}
		}
		scanf("%d %d", &bombj, &bombi);
		val = solve(bombi, bombj);
		printf("%d\n", val);
	}
	return 0;
}

