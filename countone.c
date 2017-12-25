#include <stdio.h>


int count_one(unsigned int n)
{
	int count = 0;
	while (n != 0) {
		n = (n-1)&n;
		count++;
	}
	return count;
}

int main()
{
	unsigned int n=0;
	int count = 0;
	printf("Enter a number: ");
	scanf("%d", &n);
	count = count_one(n);
	printf("Number of one's = %d\n", count);
	return 0;
}


