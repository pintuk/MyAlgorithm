
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INFINITY        (-9999)
#define MAX(a, b)       ((a > b) ? (a) : (b))
#define MIN(a, b)       ((a < b) ? (a) : (b))
#define GRAPHSIZE	(1000)

int dist[GRAPHSIZE][GRAPHSIZE];
int treepath[GRAPHSIZE][GRAPHSIZE];
int N;

void PrintGraph()
{
	int i,j;

	for(i=1; i<=N; i++) {
		for (j=1; j<=N; j++) {
			printf("%8d ", dist[i][j]);
		}
		printf("\n");
	}
}

void printD(int d[], int n)
{
	int i;
	printf("d[] = ");
	for(i=0; i<n; i++) {
		printf("%d   ",d[i]);
	}
	printf("\n");
}

int FindMaxVertex(int d[], int n, int visited[])
{
	int i;
	int max=-1;
	int v = 0;
	for(i=1; i<=n; i++) {
		if(!visited[i]) {
			if(d[i] > max) {
				max = d[i];
				v = i;
			}
		}
	}
	return v;
}

void prims() 
{
	int i; int k = 0;
	int visited[GRAPHSIZE];
	int d[GRAPHSIZE];
	int source = 1;
	int prev[GRAPHSIZE];

	for (i = 0; i <= N; ++i) {
		d[i] = INFINITY;
		visited[i] = 0; /* the i-th element has not yet been visited */
		prev[i] = -1;
	}
	d[source] = 0;
	prev[source] = -1;
	for(i=source; i<=N; i++) {
		int v = 0;
		v = FindMaxVertex(d,N,visited);
		visited[v] = 1;
		for(k=1; k<=N; k++) {
			if(!visited[k]) {
				if(dist[v][k] > d[k]) {
					d[k] = dist[v][k];
					prev[k] = v;
				}
			}
		}
	}
	for(i=1; i<=N; i++) {
		if(prev[i] != -1) {
			treepath[prev[i]][i] = d[i];
		}
	}
}


void reset()
{
	int i,j;

	for(i=0; i<=N; i++) {
		for (j=0; j<=N; j++) {
			dist[i][j] = INFINITY;
			treepath[i][j] = INFINITY;
		}
	}
}

int main()
{
        int i,j;
	int M;
	int a,b,c;
	int minvalue, maxvalue;
	int finalval = 0;

        scanf("%d",&N);
	scanf("%d", &M);
        //memset(&dist,0,sizeof(dist));
        //memset(&treepath,INFINITY,sizeof(treepath));
	reset();
	for(i=1; i<=M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		dist[a][b] = dist[b][a] = c;
	}
	PrintGraph();
	prims();
	minvalue = 9999;
	maxvalue = -9999;
	printf("The minimum spanning tree is:\n");
	for(i=1; i<=N; i++) {
		for(j=1; j<=N; j++) {
			if(treepath[i][j] != INFINITY) {
				printf("(%d->%d) - [%d]\n",i,j,treepath[i][j]);
				if (treepath[i][j] < minvalue)
					minvalue = treepath[i][j];
				if (treepath[i][j] > maxvalue)
					maxvalue = treepath[i][j];
			}
		}
	}
	finalval = maxvalue - minvalue;
	printf("Answer = %d\n", finalval);
	printf("\n");

        return 0;
}


