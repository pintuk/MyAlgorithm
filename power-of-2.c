#include <stdio.h>

int ispower2(int N)
{
	return (N && !(N & (N - 1)));
}

int main()
{
	int N, Answer;

	scanf("%d", &N);
	Answer = ispower2(N);
	if (Answer == 1)
		printf("this number is power of 2\n");
	else
		printf("number is NOT power of 2\n");

	return 0;
}
