
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INFINITY        (9999)
#define MAX(a, b)       ((a > b) ? (a) : (b))
#define MIN(a, b)       ((a < b) ? (a) : (b))
#define GRAPHSIZE	(100)


void Showpath(int path[], int n)
{
	int i=0;

	for(i=0; i<n; i++) {
		printf("%d\t",path[i]);
	}
	printf("\n");
}


int FindNextMinVertex(int d[], int n, int *visited)
{
	int i;
	int min=INFINITY;
	int v = 0;
	for(i=0; i<n; i++) {
		if(!visited[i]) {
			if(d[i] < min) {
				min = d[i];
				v = i;
			}
		}
	}
	return v;
}

void dijkstra(int dist[][GRAPHSIZE], int n, int source, int d[], int path[]) {
	int i, k, x;
	int visited[GRAPHSIZE];
	int prev[GRAPHSIZE];
	//int d[GRAPHSIZE];

	for (i = 0; i < n; ++i) {
		d[i] = INFINITY;
		//path[i][0] = 0;
		visited[i] = 0; /* the i-th element has not yet been visited */
		path[i] = INFINITY;
		prev[i] = -1;
	}
	x=0;
	d[source] = 0;
	prev[source] = -1;
	path[x++] = source;
	//path[source][0] = source;
	for(i=source; i<n; i++) {
		int v = 0;
		v = FindNextMinVertex(d,n,visited);
		visited[v] = 1;
		for(k=0; k<n; k++) {
			if(!visited[k]) {
				//d[k] = MIN(d[k],(d[v]+dist[v][k]));
				if( (d[v] + dist[v][k]) < d[k] ) {
					d[k] = (d[v] + dist[v][k]);
					prev[k] = v;
				}
			}
		}
		//printD(d,n);
	}
	Showpath(prev,n);
	for(i=0; i<n; i++) {
		if((prev[i] != -1) && (prev[i] != 0)) {
			path[x++] = prev[i];
		}
	}
	Showpath(path,n);
}

void PrintPath(int path[], int dest)
{
	if(path[dest] == -1) {
		printf(" -> %d", dest);
		return;
	}
	PrintPath(path, path[dest]);
	printf(" -> %d", dest);
}

int main()
{
        int i,j;
        int n;
        int dist[GRAPHSIZE][GRAPHSIZE];
	int source=0;
	int shortest[GRAPHSIZE];
	//int path[GRAPHSIZE][GRAPHSIZE];
	int path[GRAPHSIZE];

        printf("Enter the number of nodes: ");
        scanf("%d",&n);
        memset(&dist,0,sizeof(dist));
        memset(&path,0,sizeof(path));
	printf("Enter the distance for connected vertices:\n");
        for(i=0; i<n; i++)
        {
                for(j=0; j<n; j++)
                {
                        scanf("%d",&dist[i][j]);
                        if(dist[i][j] == 0) dist[i][j] = INFINITY;
			//path[i][j] = INFINITY;
                }
        }
	source = 0;
	dijkstra(dist, n, source, shortest, path);
	printf("shortest distance:\n");
	for(i=0; i<n; i++) {
		printf("%d->%d : ",source,i);
		printf("Path(");
		//PrintPath(path, i);
		for(j=0; j<n; j++) {
			if(path[j] != INFINITY) {
				printf(" --> %d",path[j]);
			}
		}
		printf(") ");
		printf(": Length(%d)\n",shortest[i]);
	}

        return 0;
}


