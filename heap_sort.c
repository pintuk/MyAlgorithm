#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXSIZE		100

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
		printf("%d   ",A[i]);
	}
	printf("\n");
}


void BuildHeap(int A[], int n)
{
	int i;
	int root, child, parent;

	root = 0;
	printf("Build Heap.....\n");
	parent = root;
	for (i = 1; i < n; i++) {
		child = i;
		while (child > 0) {
			parent = (child - 1)/2;
			if (A[parent] < A[child]) {
				SWAP(A[parent], A[child]);
				child = parent;
			}
			else {
				break;
			}
		}
	}
}


void Heapsort(int A[], int n)
{
	int end = 0; int max = 0;

	//build the heap-tree.
	BuildHeap(A, n);
	end = n - 1;
	while (end > 0) {
		//swap max with last element
		SWAP(A[0], A[end]);
		//build heap again
		BuildHeap(A, end);
		end = end - 1;
	}
}

int main()
{
	int i=0; int n=0;
	int A[MAXSIZE];

	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter the heap elements: \n");
	for(i=0; i<n; i++)
		scanf("%d",&A[i]);

	Heapsort(A,n);
	printf("The sorted elements are: \n");
	PrintElement(A, n);

	return 0;
}

