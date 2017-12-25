#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXSIZE         100

#define SWAP(a,b)  do { \
                        int t=0; \
                        t = a; \
                        a = b; \
                        b = t; \
                   } while(0)


void PrintElement(int A[], int n)
{
        int i = 0;

        for(i=0; i<n; i++)
        {
                printf("%d\t",A[i]);
        }
        printf("\n");
}


int FindPartition(int A[], int low, int high)
{
	int key = 0;
	int i,j;

	key = A[low];
	i = low; j = high;

	printf("FindPartition: key: %d, i: %d, j: %d\n",key,i,j);
	while(i <= j) {
		while(key >= A[i]) i++;
		while(key < A[j]) j--;
		if(i < j) {
			printf("(i < j) : SWAP - (%d, %d)\n",A[i],A[j]);
			SWAP(A[i], A[j]);
		}
		else {
			printf("(i >= j) : SWAP - (%d, %d)\n",A[low],A[j]);
			SWAP(A[low], A[j]);
		}
	}
	return j;
}

int Quicksort(int A[], int n, int low, int high)
{
	int partition = 0;
	
	if(low < high) {
		printf("-> low: %d , high: %d\n",low,high);
		partition = FindPartition(A,low,high);
		//printf("Partition Element: (%d) ->\n",A[j]);
		printf("partition: %d\n", partition);
		PrintElement(A,n);
		printf("\n==========================================\n");
		Quicksort(A,n,low,partition-1);
		//printf("1 -> low: %d , high: %d\n",low,high);
		PrintElement(A,n);
		printf("-----------------------------------------\n");
		Quicksort(A,n,partition+1,high);
		//printf("2 -> low: %d , high: %d\n",low,high);
		PrintElement(A,n);
		printf("-----------------------------------------\n");
	}
}


int main()
{
        int i=0; int n=0;
        int A[MAXSIZE];
        int low,high;

        printf("Enter the number of elements: ");
        scanf("%d",&n);
        printf("Enter the elements: \n");
        for(i=0; i<n; i++)
                scanf("%d",&A[i]);

        low = 0; high = (n-1);
        Quicksort(A,n,low,high);
        printf("The sorted elements are: \n");
        PrintElement(A, n);

        return 0;
}

