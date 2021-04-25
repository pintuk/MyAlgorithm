#include <stdio.h>

#define MAX(a,b)	(((a) > (b)) ? (a) : (b))

int N;


int issafe(int x, int y)
{
	if ((x > 0) && (x <= N) && (y > 0) && (y <= 5))
		return 1;
	return 0;
}

int solve(int x, int y, int count)
{
	if (!issafe(x,y))
		return 0;

	if (plane[x][y] == 2)
		count--;

	if (plane[x][y] == 1) {
		count++;
		x = x-1;
	}
	solve(x, y-1, count);
	solve(x, y+1, count);
	solve(x, y, count);

	return count;
}

int 
