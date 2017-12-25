#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX(a,b)	((a) > (b)) ? (a) : (b)
#define SIZE	100


int K[SIZE+1][SIZE+1];
int Weight[SIZE+1];
int Value[SIZE+1];


void PrintTable(int n, int W)
{
        int i,j;

        for(i=0; i<=n; i++) {
                for(j=0; j<=W; j++) {
                        printf("%d\t",K[i][j]);
                }
                printf("\n");
        }
        printf("\n");
        printf("----------------------------\n");
}

void Initialize(int n, int W)
{
	int i,j;

	memset(Weight, 0, sizeof(Weight));
	memset(Value, 0, sizeof(Value));
	//memset(K, -1, sizeof(K));
	for(i=0; i<=n; i++)
		K[i][0] = 0;
	for(j=0; j<=W; j++)
		K[0][j] = 0;

	PrintTable(n,W);
}


int Knapsack(int n, int W)
{
	int i,j;
	int w;
	int opval=0;

	for(i=1; i<=n; i++) {
		for(j=1; j<=W; j++) {
			if(Weight[i] > j) {
				K[i][j] = K[i-1][j];
			}
			else {
				K[i][j] = MAX(K[i-1][j], (K[i-1][j-Weight[i]] + Value[i]));
			}
		}
	}
	PrintTable(n,W);
	opval = K[i-1][j-1];

	return opval;
}

int main()
{
	int i,j;
	int n=0;
	int Capacity=0;
	int opcost = 0;

	printf("Enter the number of items: ");
	scanf("%d",&n);
	printf("Enter the capacity: ");
	scanf("%d",&Capacity);
	Initialize(n, Capacity);
	
	printf("Enter each items <Weight> <Value>:\n");
	for(i=1; i<=n; i++)
		scanf("%d %d",&Weight[i],&Value[i]);

	opcost = Knapsack(n, Capacity);
	printf("Optimal Cost = %d\n",opcost);

	return 0;
}


