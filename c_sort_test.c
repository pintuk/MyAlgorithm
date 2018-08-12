#include <stdio.h>
#include <stdlib.h>


int compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

void display(int *A, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d  ", A[i]);
	printf("\n");
}

int main()
{
	int n;
	int A[] = {4,5,2,3,1,0,9,8,6,7};

	n = sizeof(A)/sizeof(A[0]);
	printf("Before:\n");
	display(A,n);
	/* As per man page, qsort is faster than mergesort, than heapsort */
	qsort(A,n,sizeof(int),compare);
	//mergesort(A,n,sizeof(int),compare);
	//heapsort(A,n,sizeof(int),compare);
	printf("After:\n");
	display(A,n);

	return 0;
}
