#include <stdio.h>
#include <stdlib.h>

#define ABS(a)  (((a) < 0) ? -(a) : (a))

int N;
int locx[100] = {0,};
int locy[100] = {0,};


int calculate_dist(int x1, int y1, int x2, int y2)
{
	return ABS(x1 - x2) + ABS(y1 - y2);
}

int shortest_path(int start, int locx[], int locy[], int *lastx, int *lasty)
{
	int i,j;
	int d;
	int min = 99999;
	int pos = 0;
	int visited[100] = {0,};
	static int path = 0;

	visited[start] = 1;

	if (N == 0) return 0;

	for (i=0; i<N; i++) {
		if (!visited[i]) {
			d = calculate_dist(locx[start], locy[start], locx[i], locy[i]);
			if (d < min) {
				min = d;
				pos = i;
			}
		}
		*lastx = locx[pos];
		*lasty = locy[pos];
		path += shortest_path(pos, locx, locy, lastx, lasty);
	}
	return path;
}

int main()
{
	int i,j,d,p;
	int x,y,ox,oy,hx,hy;
	int dist = 0;
	int d1,d2,d3;
	int lastx,lasty;
	int min = 99999;

	d = 0;
	scanf("%d", &N);
	scanf("%d %d %d %d", &ox, &oy, &hx, &hy);
	for (i=0; i<N; i++) {
		scanf("%d %d", &x, &y);
		locx[i] = x;
		locy[i] = y;
	}
	p = 0;
	for (i=0; i<N; i++) {
		d1 = calculate_dist(ox, oy, locx[i], locy[i]);
		d2 = shortest_path(i, locx, locy, &lastx, &lasty);
		d3 = calculate_dist(lastx, lasty, hx, hy);
		d = d1 + d2 + d3;
		printf("pos: %d, dist = %d\n", p,dist);
		if (d < min)
			min = d;
	}
	printf("pos: %d, dist = %d\n", p,dist);
	printf("Answer: %d\n", min);

	return 0;
}

