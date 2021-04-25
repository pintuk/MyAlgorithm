#include <stdio.h>

int M,N;
int L;
int R,C;
int pipe[100][100];
int visited[100][100];

int Left[] = {1,3,6,7};
int Right[] = {1,3,4,5};
int Up[] = {1,2,4,7};
int Down[] = {1,2,5,6};


int explore(int x, int y)
{
	int i;


	//LEFT
	p = explore(x,y-1);
	//RIGHT
	p = explore(x,y+1);
	//UP
	p = explore(x-1,y);
	//DOWN
	p = explore(x+1,y);
}


int main()
{
}

