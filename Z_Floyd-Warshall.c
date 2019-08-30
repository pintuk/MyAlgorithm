#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INFINITY        (9999)
#define MAXSIZE		(100)

#define MIN(a,b)	((a) < (b)) ? (a) : (b)

void FloydWarshall(int n, int A[][MAXSIZE])
{
	int i,j,k = 0;

	for(k=0; k<n; k++) {
		for(i=0; i<n; i++) {
			for(j=0; j<n; j++) {
				//if(A[i][j] == 0)
					A[i][j] = MIN(A[i][j],(A[i][k] + A[k][j]));
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
                        printf("%d\t\t", A[i][j]);
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
	printf("Enter the edges of a graph: \n");
	for(i=0; i<n; i++)
	for(j=0; j<n; j++) {
		scanf("%d", &A[i][j]);
		if(A[i][j] == 0) A[i][j] = INFINITY;
		if(i==j) A[i][j] = 0;
	}

	printf("The Original Graph Matrix is:\n");
	PrintGraph(n, A);
	FloydWarshall(n,A);
	printf("The All Pair Shortest Path Matix is:\n");
	PrintGraph(n, A);

	return 0;
}


