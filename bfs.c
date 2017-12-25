#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INFINITY        (9999)
#define GRAPHSIZE       (100)
#define QUEUE_SIZE      GRAPHSIZE

int Queue[QUEUE_SIZE];
int front = -1;
int rear = -1;

void enqueue(int item)
{
        rear = rear + 1;
        if(rear >= QUEUE_SIZE) {
                printf("Queue is full....\n");
                return;
        }
        Queue[rear] = item;
}

int dequeue()
{
	int item = 0;
        if(front == rear) {
                printf("Queue is empty....\n");
                return -1;
        }
        item = Queue[front];
        front = front + 1;
}

int QueueEmpty()
{
        if(front == rear) return 1;
        else
        return 0;
}


void bfs(int dist[][GRAPHSIZE], int n, int start, int visited[], int nodes[])
{
        int i = 0;
        int k = 0;

	enqueue(start);
        visited[start] = 1;
	nodes[k++] = start;
	while(!QueueEmpty()) {
		int j=0;
		j = dequeue();
		//nodes[k++] = j;
        	for(i=0; i<n; i++) {
                	if((dist[j][i] != INFINITY) && (!visited[i])) {
				visited[i] = 1;
				enqueue(i);
				nodes[k++] = i;
                	}
		}
        }
}



void Findbfs(int dist[][GRAPHSIZE], int n, int start, int nodes[])
{
	int i; int k = 0;
	int visited[GRAPHSIZE];

	memset(visited,0,sizeof(visited));
	bfs(dist,n,start,visited,nodes);
}

int main()
{
	int i,j;
	int n;
	int dist[GRAPHSIZE][GRAPHSIZE];
	int nodes[GRAPHSIZE];
	int start = 0;

	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	memset(&dist,0,sizeof(dist));
	memset(&nodes,0,sizeof(nodes));

	printf("Enter the distance for connected vertices:\n");
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			scanf("%d",&dist[i][j]);
			if(dist[i][j] == 0) dist[i][j] = INFINITY;
		}
	}
	printf("Enter the starting node: ");
	scanf("%d",&start);
	Findbfs(dist, n, start, nodes);
	printf("The Breadth First Search nodes are:\n");
	for(i=0; i<n; i++) {
		printf("%d, ",nodes[i]);
	}
	printf("\n");

	return 0;
}

