#include <stdio.h>

int N;
int A[20];


diceroll(int n)
{
	int i;

	if (n == 0) {
		for (i=1; i<=N; i++)
			printf("%d  ", A[i]);
		printf("\n");
		return 0;
	}
	for (i=1; i<=6; i++) {
		A[n] = i;
		diceroll(n-1);
		//A[n] = 0;
	}
}

//void solve(int n)
//{
//	diceroll(n);
//}

int main()
{
	scanf("%d", &N);
	diceroll(N);

	return 0;
}
