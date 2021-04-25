#include <stdio.h>
//using namespace std;

int A[10];
int N,R;
int count = 0;

void store(int *A)
{
	int i;

	for (i=0; i<R; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

void function(int i)
{
	int j;
	int x;

	if (i == R) { 
		store(A);
		count++;
		return; 
	}
	//x = ((i != 0) ? A[i-1]+1 : 1);
	for (j=1; j<=N; j++) {
		A[i] = j;
		function(i+1);
	}
	return;
}

int main() 
{
	scanf("%d %d", &N, &R);
	function(0);
	printf("Total = %d\n", count);
	return 0;
}
