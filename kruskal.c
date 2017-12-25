
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INFINITY        (9999)
#define MAX(a, b)       ((a > b) ? (a) : (b))
#define MIN(a, b)       ((a < b) ? (a) : (b))
#define GRAPHSIZE	(100)


void printD(int d[], int n)
{
	int i;
	printf("d[] = ");
	for(i=0; i<n; i++) {
		printf("%d   ",d[i]);
	}
	printf("\n");
}

int FindNextMinVertex(int dist[][GRAPHSIZE], int n, int visited[][GRAPHSIZE], int *u, int *v)
{
	int i,j;
	int min=INFINITY;
	//int v = 0;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			if(!visited[i][j]) {
				if(dist[i][j] < min) {
					min = dist[i][j];
					*u = i;
					*v = j;
				}
			}
		}
	}
	return min;
}

void Makeset(int parent[], int i)
{
	parent[i] = i;
}

int Findset(int parent[], int i)
{
	if(parent[i] == -1) return i;
	return Findset(parent, parent[i]);
}

int Union(int parent[], int x, int y)
{
	int xset = Findset(parent, x);
	int yset = Findset(parent, y);
	
	parent[xset] = yset;
}

int iscycle(int treepath[][GRAPHSIZE], int n, int start, int end)
{
	int i;
	int parent[GRAPHSIZE];
	int x,y;

	memset(parent,(-1),sizeof(parent));
	for(i=0; i<n; i++) {
		//Makeset(parent,i);
		x = Findset(parent, treepath[i][start]);
		y = Findset(parent, treepath[i][end]);
		
		if(x == y) return 1;
		Union(parent, x, y);
	}
	return 0;
}

void kruskal(int dist[][GRAPHSIZE], int n, int treepath[][GRAPHSIZE]) {
	//int i; int k = 0;
	int visited[GRAPHSIZE][GRAPHSIZE];
	int parent[GRAPHSIZE];
	//int prev[GRAPHSIZE];

	//prev[source] = -1;
	memset(visited,0,sizeof(visited));
	memset(parent,(-1),sizeof(parent));
	while(1) {
		int v = 0;
		int u = 0;
		int len = 0;
		len = FindNextMinVertex(dist,n,visited,&u,&v);
		if (len == INFINITY) break;  //no more vertices to visit
		printf("NEXT Min Vertices : (u,v) = (%d, %d) ==> [%d]\n", u,v,dist[u][v]);
		visited[u][v] = 1;
		Makeset(parent,u); Makeset(parent,v);
		//treepath[u][v] = dist[u][v];
		//if(iscycle(treepath,n,u,v)) {
		if(Findset(parent,u) != Findset(parent,v)) {
			Union(parent,u,v);
			treepath[u][v] = dist[u][v]; //INFINITY;
		}
	}
}


int main()
{
        int i,j;
        int n;
        int dist[GRAPHSIZE][GRAPHSIZE];
	int treepath[GRAPHSIZE][GRAPHSIZE];

        printf("Enter the number of nodes: ");
        scanf("%d",&n);
        memset(&dist,0,sizeof(dist));
	printf("Enter the distance for connected vertices:\n");
        for(i=0; i<n; i++)
        {
                for(j=0; j<n; j++)
                {
                        scanf("%d",&dist[i][j]);
                        if(dist[i][j] == 0) dist[i][j] = INFINITY;
			treepath[i][j] = INFINITY;
                }
        }
	kruskal(dist, n, treepath);
	printf("The KRUSKAL minimum spanning tree is:\n");
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			if(treepath[i][j] != INFINITY)
				printf("(%d->%d) - [%d]\n",i,j,treepath[i][j]);
		}
	}
	printf("\n");

        return 0;
}


