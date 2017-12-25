#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXSIZE		(100)



void Warshall(int n, int A[][MAXSIZE])
{
	int i,j,k = 0;

	for(k=0; k<n; k++) {
		for(i=0; i<n; i++) {
			for(j=0; j<n; j++) {
				if(A[i][j] == 0)
					A[i][j] = A[i][k] & A[k][j];
			}
		}
	}
}

int PrintGraph(int n, int A[][MAXSIZE])
{
	int i,j = 0;
        for(i=0; i<n; i++)
        {
                for(j=0; j<n; j++)
                {
                        printf("%d   ", A[i][j]);
                }
                printf("\n");
        }
}

int main()
{
	int i,j = 0;
	int n=0;
	int A[MAXSIZE][MAXSIZE];

	printf("Enter the no. of nodes: ");
	scanf("%d",&n);
	printf("Enter the Adjacency Matrix of a graph: \n");
	for(i=0; i<n; i++)
	for(j=0; j<n; j++) {
		scanf("%d", &A[i][j]);
	}

	printf("The Original Adjacency Matrix is:\n");
	PrintGraph(n, A);
	Warshall(n,A);
	printf("The Transitive closure is:\n");
	PrintGraph(n, A);

	return 0;
}


