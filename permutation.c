#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_SIZE	100
#define SWAP(a,b)  do { \
                        char t = 0; \
                        t = a; \
                        a = b; \
                        b = t; \
                   } while(0)


int N=0;

void Print_Result(int n, char A[])
{
	int i;
	printf("(");
	for (i=0; i<n; i++) {
		printf("%c,", A[i]);
	}
	printf("), ");

	printf("\n");
}

int heap_permute(int n, char A[])
{
	int i;

	if (n == 1) {
		Print_Result(N, A);
		//printf("%d, ", A[n]);
	}
	else {
		for (i=0; i<n; i++) {
			heap_permute(n-1, A);
			if ( (n%2) != 0)
				SWAP(A[1], A[n-1]);
			else
				SWAP(A[i], A[n-1]);
		}
	}
	return 0;
}


int main()
{
	int i;
	int n;
	char A[MAX_SIZE];

	printf("Enter the number of elements: ");
	scanf("%d", &n);
	N = n;
	memset(A,0,sizeof(A));
	printf("Enter the elements: \n");
	scanf("%s",A);
	//for (i=1; i<=n; i++) {
	//	scanf("%c", &A[i]);
	//}
	heap_permute(n, A);
	printf("\n");
}

