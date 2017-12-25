#include <stdio.h>

#define MAX(a,b)	((a) > (b) ? (a) : (b))
#define QSIZE		(25*25 + 2)

int N;
int Grid[25][25];
int temp[25][25];
int blocks[25][25];

struct Queue {
	int x;
	int y;
	int dir;
	int count;
	int size;
} Q[QSIZE];

enum DIR {
	UP = 0,
	LEFT,
	RIGHT,
	DOWN,
};

struct Queue queue = {0,0,0,0,0};

int front = -1;
int rear = -1;

void insertQ(int x, int y, int dir, int count)
{
	rear++;
	Q[rear].x = x;
	Q[rear].y = y;
	Q[rear].dir = dir;
	Q[rear].count = count;

	queue.size++;
}

void removeQ(int *x, int *y, int *dir, int *count)
{
	*x = Q[front].x;
	*y = Q[front].y;
	*dir = Q[front].dir;
	*count = Q[front].count;

	front++;
	queue.size--;
}

int isempty()
{
	if (queue.size == 0)
		return 1;

	return 0;
}

int issafe(int x, int y)
{
	if (x > 0 && x <= N && y > 0 && y <= N)
		return 1;

	return 0;
}

int count_blocks()
{
	int i,j;
	int count = 0;

	for (i=1; i<=N; i++) {
		for (j=1; j<=N; j++) {
			if (blocks[i][j] != 0)
				count++;
		}
	}
	return count;
}

int all_destroyed()
{
	int i,j;

	for (i=1; i<=N; i++) {
		for (j=1; j<=N; j++) {
			if (temp[i][j] != 0)
				return 0;
		}
	}
	return 1;
}

int all_zeros(int x, int y, int dir)
{
	int i;

	switch (dir) {
		case UP:
		case DOWN:
			for (i=1; i<=N; i++) {
				if (temp[i][y] != 0)
					return 0;
			}
		break;

		case LEFT:
		case RIGHT:
			for (i=1; i<=N; i++) {
				if (temp[x][i] != 0)
					return 0;
			}
		break;
	}
	return 1;
}

void rotate(int *x, int *y, int dir)
{
	switch (dir) {
		case UP:
			if (*x < 1) {
				*x = N;
				if (*y < 1)
					*y = 1;
				else if (*y > N)
					*y = N;
			}
		break;

		case LEFT:
			if (*y < 1) {
				*y = N;
				if (*x < 1)
					*x = 1;
				else if (*x > N)
					*x = N;
			}
		break;

		case RIGHT:
			if (*y > N) {
				*y = 1;
				if (*x < 1)
					*x = 1;
				else if (*x > N)
					*x = N;
			}
		break;

		case DOWN:
			if (*x > N) {
				*x = 1;
				if (*y < 1)
					*y = 1;
				else if (*y > N)
					*y = N;
			}
		break;
	}

}

//Block types

/*

1) up(0) -> down(3) ; left(1) -> up(0) ; right(2) -> left(1) ; down(3) -> right(2)
|\
| \
|__\

2) up(0) -> down(3) ; left(1) -> right(2) ; right(3) -> up(0) ; down(3) -> left(1)
  /|
 / |
/__|


3) up(0) -> right(2) ; left(1) -> down(3) ; right(2) -> left(1) ; down(3) -> up(0)
|--
| /
|/

4) up(0) -> left(1) ; left(1) -> right(2) ; right(2) -> down(3) ; down(3) -> up(0)
---|
\  |
 \ |
  \|

5) up(0) -> down(3) ; left(1) -> right(2) ; right(2) -> left(1) ; down(3) -> up(0)
|---|
|   |
|---|

*/

void change_dir(int type, int *dir)
{
	switch (type) {
		case 0:
		break;

		case 1:
			if (*dir == UP)
				*dir = DOWN;
			else if (*dir == LEFT)
				*dir = UP;
			else if (*dir == RIGHT)
				*dir = LEFT;
			else if (*dir == DOWN)
				*dir = RIGHT;
		break;

		case 2:
			if (*dir == UP)
				*dir = DOWN;
			else if (*dir == LEFT)
				*dir = RIGHT;
			else if (*dir == RIGHT)
				*dir = UP;
			else if (*dir == DOWN)
				*dir = LEFT;
		break;

		case 3:
			if (*dir == UP)
				*dir = RIGHT;
			else if (*dir == LEFT)
				*dir = DOWN;
			else if (*dir == RIGHT)
				*dir = LEFT;
			else if (*dir == DOWN)
				*dir = UP;
		break;

		case 4:
			if (*dir == UP)
				*dir = LEFT;
			else if (*dir == LEFT)
				*dir = RIGHT;
			else if (*dir == RIGHT)
				*dir = DOWN;
			else if (*dir == DOWN)
				*dir = UP;
		break;

		case 5:
			if (*dir == UP)
				*dir = DOWN;
			else if (*dir == LEFT)
				*dir = RIGHT;
			else if (*dir == RIGHT)
				*dir = LEFT;
			else if (*dir == DOWN)
				*dir = UP;
		break;
	}
}

int bfs(int x, int y, int dir, int count)
{
	int maxvalue = 0;
	front = 0;
	rear = -1;
	queue.size = 0;
	insertQ(x, y, dir, count);

	while (!isempty()) {
		int px,py,pdir,pcount;
		int i;
		int dx[] = {-1,1,0,0};
		int dy[] = {0,0,-1,1};

		removeQ(&px,&py,&pdir,&pcount);
		
		if (all_destroyed() == 1 || all_zeros(x,y,dir) == 1) {
			pcount = count_blocks();
			if (pcount > maxvalue)
				maxvalue = pcount;
			break;
		}
		for (i=0; i<4; i++) {
			int type,value;
			int a,b;

			a = px + dx[i];
			b = py + dy[i];

			if (!issafe(a,b)) {
				rotate(&a,&b,dir);
			}
			type = temp[a][b]/10;
			value = temp[a][b] % 10;
			change_dir(type, &dir);
			if (temp[a][b] != 0) {
				blocks[a][b]++;
				if (value == 0)
					temp[a][b] = 0;
				else
					temp[x][y]--;
			}
			insertQ(a,b,dir,pcount);
		}
	}
	return maxvalue;
}

void reset()
{
	int i,j;

	for (i=1; i<=N; i++) {
		for (j=1; j<=N; j++) {
			temp[i][j] = Grid[i][j];
			blocks[i][j] = 0;
		}
	}
}

int main()
{
	int t,T;

	scanf("%d", &T);
	for (t=1; t<=T; t++) {
		int i,j;
		int Answer = 0;
		int value = 0;

		scanf("%d", &N);
		for (i=1; i<=N; i++) {
			for (j=1; j<=N; j++) {
				scanf("%d", &Grid[i][j]);
				temp[i][j] = Grid[i][j];
				blocks[i][j] = 0;
			}
		}
		for (i=1; i<=N; i++) {
			for (j=1; j<=N; j++) {
				if (Grid[i][j] == 0) {
					int v1=0,v2=0,v3=0,v4=0;
					reset();
					v1 = bfs(i,j,UP,0);
					reset();
					v2 = bfs(i,j,DOWN,0);
					reset();
					v3 = bfs(i,j,LEFT,0);
					reset();
					v4 = bfs(i,j,RIGHT,0);
					value = MAX(MAX(v1,v2), MAX(v3,v4));
					if (value > Answer)
						Answer = value;
				}
			}
		}
		printf("#%d %d\n", t, Answer);
	}

	return 0;
}



