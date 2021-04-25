#include <stdio.h>

#define MAX(a,b)	(((a) > (b)) ? (a) : (b))

int price[100];
int L[101];


void initialize_table(int n)
{
	int i;
	for (i=0; i<=n; i++)
		L[i] = -1;
}

int cut_rod(int n)
{
	int i;

	if (n < 0)
		return -1;
	if (n == 0)
		return 0;
	if (n == 1)
		return price[1];
	if (L[n] != -1)
		return L[n];

	for(i=1; i<=n; i++) {
		L[n] = MAX(L[n], price[i] + cut_rod(n - i));
		printf("L[%d] = %d\n", i,L[i]);
	}
	return L[n];
}

int main()
{
	int i;
	int answer = -1;
	int n;

	scanf("%d", &n);
	for (i=1; i<=n; i++)
		scanf("%d", &price[i]);
	initialize_table(n);
	L[0] = price[1];
	answer = cut_rod(n);
	printf("Length(%d), Answer: %d\n", n,answer);

	return 0;
}

