
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INFINITY        (9999)
#define MAX(a, b)       ((a > b) ? (a) : (b))
#define MIN(a, b)       ((a < b) ? (a) : (b))
#define GRAPHSIZE	(100)

int Graph[GRAPHSIZE][GRAPHSIZE];
int nodes[GRAPHSIZE];
int visited[GRAPHSIZE];
int N;

void dfs(int start)
{
	int j = 0;
	static int k = 0;

	if (start >= N)
		return;

	if (visited[start] == 1)
		return;

	visited[start] = 1;
	nodes[k++] = start;
	for(j=0; j<N; j++) {
		if((Graph[start][j] != 0) && (!visited[j])) {
			dfs(j);
		}
	}
}

int main()
{
        int i,j;
	int start=0;

        printf("Enter the number of nodes: ");
        scanf("%d",&N);
        memset(&Graph,0,sizeof(Graph));
        memset(&nodes,-1,sizeof(nodes));
	memset(&visited,0,sizeof(visited));
	printf("Enter the distance for connected vertices:\n");
        for(i=0; i<N; i++) {
                for(j=0; j<N; j++) {
                        scanf("%d",&Graph[i][j]);
                }
        }
	printf("Enter the starting node: ");
	scanf("%d",&start);
	dfs(start);
	printf("The Depth First Search nodes are:\n");
	for(i=0; i<N; i++) {
		if (nodes[i] != -1)
			printf("[%d] \n",nodes[i]);
	}
	printf("\n");

        return 0;
}


