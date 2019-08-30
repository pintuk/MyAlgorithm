#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int binary_search(int A[], int N, int key)
{
	int low = 0;
	int high = 0;
	int mid = 0;

	low = 0; high = N - 1;

	while (low <= high) {
		mid = (low + high) / 2;
		if (key == A[mid])
			return mid;
		else if (key < A[mid]) 
			high = mid - 1;
		else if (key > A[mid])
			low = mid + 1;
	}
	return -1;
}


int main()
{
	int i, N, key, pos = -1;
	int A[50];

	printf("Enter the number of items: ");
	scanf("%d",&N);
	printf("Enter the items: \n");
	for(i = 0; i < N; i++)
		scanf("%d", &A[i]);
	printf("Enter the item to search: ");
	scanf("%d", &key);
	pos = binary_search(A, N, key);

	if(pos >= 0) 
		printf("Item found at: %d\n", pos);
	else
		printf("Item not found....\n");

	return 0;
}
