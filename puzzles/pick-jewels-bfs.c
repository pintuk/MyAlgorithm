#include <stdio.h>

#define INFINITY        0x7fffffff

int maze[101][101];
int N;
int sx,sy,ex,ey;
int maxvalue = -1;
int visited[101][101];
int track[101][101];


#define QSIZE	(101 * 101 + 2)

struct Queue {
	int x;
	int y;
	int count;
	int size;
} Q[QSIZE];

struct Queue queue = {0,0,0,0};
int front = -1;
int rear = -1;

void insertQ(int x, int y, int count)
{
	if (queue.size > QSIZE)
		return;

	rear++;
	Q[rear].x = x;
	Q[rear].y = y;
	Q[rear].count = count;

	queue.size++;
}

void removeQ(int *x, int *y, int *count)
{
	if (queue.size <= 0)
		return;

	*x = Q[front].x;
	*y = Q[front].y;
	*count = Q[front].count;

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
        if (x > 0 && x <= N && y > 0 && y <= N && (maze[x][y] != 1))
                return 1;
        return 0;
}


void PrintMaze(int A[][101])
{
	int i,j;

	for (i=1; i<=N; i++) {
		for (j=1; j<=N; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
}

void save_path(int dest[][101], int src[][101])
{
	int i,j;

	for (i=1; i<=N; i++)
		for (j=1; j<=N; j++)
			dest[i][j] = src[i][j];
}


int solve(int x, int y, int count)
{
	int maxcount = 0;
	int mincount = INFINITY;
	int flag = 0;
	int temp = 0;

	if (!issafe(x,y))
		return count;

	front = 1;
	rear = 0;
	visited[x][y] = 1;
	queue.size = 0;

	if (maze[x][y] == 2)
		count++;
	//temp = maze[x][y];
	maze[x][y] = 3;
	insertQ(x,y,count);

	while (!isQempty()) {
		int i = 0;
		int px,py,pcount;
		int dx[] = {0,0,-1,1};
		int dy[] = {-1,1,0,0};

		removeQ(&px,&py,&pcount);
		//temp = maze[px][py];
		if (px == N && py == N) {
			if (pcount < mincount) {
				mincount = pcount;
				save_path(track, maze);
			}
			flag = 1;
			break;
		}
		for (i=0; i<4; i++) {
			int a,b;

			a = px + dx[i];
			b = py + dy[i];
			if (issafe(a,b) && !visited[a][b]) {
				visited[a][b] = 1;
				if (maze[a][b] == 2)
					pcount++;
				//temp = maze[a][b];
				maze[a][b] = 3;
				insertQ(a,b,pcount);
				//maze[a][b] = temp;
			}
		}
		//maze[px][py] = temp;
		
	}
	if (flag == 1)
		return maxcount;

	return -1;

}

int solve1(int x, int y, int count)
{
	int ret = 0;
	int prev = 0;

	if (!issafe(x,y))
		return 0;

	if (maze[x][y] == 3)
		return 0;

        if (x == N && y == N) {
		if (maze[x][y] == 2)
			count++;
		prev = maze[x][y];
		maze[x][y] = 3;
                if (count > maxvalue) {
			maxvalue = count;
			save_path(track, maze);
		}
		maze[x][y] = prev;
                return 1;
        }

	if (maze[x][y] == 2)
		count++;
	prev = maze[x][y];
	maze[x][y] = 3;

	ret = solve(x, y-1, count);
	ret |= solve(x, y+1, count);
	ret |= solve(x-1, y, count);
	ret |= solve(x+1, y, count);

	maze[x][y] = prev;
	if (maze[x][y] == 2)
		count--;

	if (ret == 1)
		return 1;

	return 0;
}


int main()
{
	int t,T;

	//freopen("sample_input_jewels.txt", "r", stdin);
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
				track[i][j] = maze[i][j];
				Q[j].x = 0;
				Q[j].y = 0;
				Q[j].count = 0;
			}
			Q[i+N].x = 0;
			Q[i+N].y = 0;
			Q[i+N].count = 0;
		}
		maxvalue = 0;
		ret = solve(1,1,0);
		printf("Case #%d\n", t);
		PrintMaze(track);
		printf("%d\n", ret);
#if 0
		if (ret == 1) {
			PrintMaze(track);
			printf("%d\n", maxvalue);
		}
		else
			printf("-1\n");
#endif
	}

	return 0;
}

