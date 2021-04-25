#include<stdio.h>

#define INFINITY        (999900)
#define MAX(a, b)       ((a > b) ? (a) : (b))
#define MIN(a, b)       ((a < b) ? (a) : (b))
#define GRAPHSIZE       (100)

int Graph[GRAPHSIZE][GRAPHSIZE];
int nodes[GRAPHSIZE];
int visited[GRAPHSIZE];
int N = 100;

void PrintGraph()
{
	int i,j;

	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			printf("%2d ", Graph[i][j]);
		}
		printf("\n");
	}
}

int dfs(int start)
{
        int j = 0;
        static int k = 0;
	int ret = 0;

        if (start >= N)
                return;

        if (visited[start] == 1)
                return;

        visited[start] = 1;
        nodes[k++] = start;
        for(j=0; j<N; j++) {
                if((Graph[start][j] != 0) && (!visited[j])) {
			if (j == 99) {
				nodes[k++] = j;
				return 1;
			} else {
                        	ret = dfs(j);
				if (ret == 1) return 1;
			}
                }
        }
	return 0;
}

void reset()
{
	int i,j;

	for(i=0; i<N; i++)
	for(j=0; j<N; j++) {
		Graph[i][j] = 0;
		visited[j] = 0;
		nodes[j] = -1;
	}
}

int main()
{
        int i,j;
	int a,b;
        int start=0;
	int C;
	int ret = 0;

        scanf("%d",&C);
	reset();
        for(i=0; i<C; i++) {
		scanf("%d %d", &a, &b);
		Graph[a][b] = 1;
        }
	//PrintGraph();
        ret = dfs(start);
	if (ret == 0) {
		printf("No path from 0 -> 99\n");
		return 0;
	}
        for(i=0; i<N; i++) {
                if (nodes[i] != -1)
                        printf("[%d] \n",nodes[i]);
        }
        printf("\n");

        return 0;
}

