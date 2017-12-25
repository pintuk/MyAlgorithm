#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX	10

int Weight[MAX];
int Value[MAX];
int K[MAX][MAX]; 
int item[MAX];
int n = 0;
int C = 0;

void PrintTable()
{
	int i,j;

	for(i=0; i<=n; i++) {
		for(j=0; j<=C; j++) {
			printf("%d   ",K[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("----------------------------\n");
}	
	

int Knapsack(int i, int w)
{
	int value1,value2,cost;

	//if(K[i][w] >= 0) return K[i][w];
	if(K[i][w] < 0) {
		value1 = value2 = cost = 0;
		if(w < Weight[i]) { 
			cost = Knapsack(i-1, w);
			item[i] = -1;
		} else {
			value1 = Knapsack(i-1,w);
			value2 = Knapsack(i-1, (w-Weight[i])) + Value[i];
			if(value2 > value1) {
				cost = value2;
				item[i] = i;
			} else {
				cost = value1;
				item[i] = -1;
			}
		}
		K[i][w] = cost;
		PrintTable();
	}
	return K[i][w];
}

void InitializeTable()
{
	int i,j;

	memset(Weight, 0, sizeof(Weight));	
	memset(Value, 0, sizeof(Value));
	memset(item, -1, sizeof(item));
	memset(K, -1, sizeof(K));
	for(i=0; i<=n; i++) {
		K[i][0] = 0;
	}
	for(i=0; i<=C; i++) {
		K[0][i] = 0;
	}
	//printf("Item \t Weight \t Value\n");
	//printf("---- \t ------ \t -----\n");
	//for(i=0; i<=n; i++)
	//printf(" %d \t %d \t %d \n",i,Weight[i],Value[i]);
	printf("----------------------------\n");
	PrintTable();
}

int main()
{
	int i;
	int cost = 0;
	
	printf("Enter the number of items: ");
	scanf("%d",&n);
	printf("Enter the capacity: ");
	scanf("%d",&C);
	InitializeTable();
	//PrintTable();
	printf("Enter the items weight & value(w v): \n");
	for(i=1; i<=n; i++) {
		scanf("%d %d",&Weight[i],&Value[i]);
	}
	cost = Knapsack(n, C);
	printf("Optimal Cost = %d\n",cost);
	for(i=1; i<=n; i++) {
		if (item[i] != -1)
			printf("%d, ",item[i]);
	}
	printf("\n");
}

