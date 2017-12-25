#include <stdio.h>

int odd_number(int A[], int N)
{
	int odd = 0;
	int i;
	
	for (i = 0; i < N; i++) {
		odd = odd ^ A[i];
	}
	return odd;
}

int main()
{
	int A[1024];
	int N,i,Answer;

	scanf("%d", &N);
	printf("Enter the numbers:\n");
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	Answer = odd_number(A, N);
	printf("The odd occurring number is: %d\n", Answer);

	return 0;
}
