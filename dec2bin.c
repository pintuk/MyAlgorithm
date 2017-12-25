#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_DIGIT	100

void dec2bin(int n, int *binary, int *s)
{
	int i=0;

	while (n != 0) {
		binary[i++] = n%2;
		n = n/2;
	}
	*s = i;
}

int main()
{
	int i=0;
	int n=0;
	int A[MAX_DIGIT];
	int s=0;

	printf("Enter a decimal number: ");
	scanf("%d", &n);

	printf("The binary equivalent is: ");
	dec2bin(n, A, &s);
	for (i=s-1; i>=0; i--)
		printf("%d", A[i]);
	printf("\n");

	return 0;
}

