#include <stdio.h>
#include <stdlib.h>


#define	ABS(a)	(((a) < 0) ? -(a) : (a))

int N, S;
int bulbs[1000];

int find_nearest(int N, int S)
{
	int i;
	int min = 99999;
	int pos = 0;

	for (i=1; i<=N; i++) {
		if (bulbs[i] == 0) continue;
		if ( ABS(S - bulbs[i]) < min) {
			min = ABS(S - bulbs[i]);
			pos = i;
		}
	}
	return pos;
}

int min_power(int N, int S)
{
	int i;
	int total = 0;
	int pos = 0;
	int count = N;

	for (i=1; i<=N; i++) {
		pos = find_nearest(N, S);
		total += count * ABS(S - bulbs[pos]);
		S = bulbs[pos];
		//printf("pos: %d, count: %d, total: %d, S: %d\n", bulbs[pos], count, total, S);
		bulbs[pos] = 0;
		count--;
	}
	return total;
}

int main()
{
	int t,i,j;
	int answer = -1;

	scanf("%d", &t);
	for (i=1; i<=t; i++) {
		scanf("%d %d\n", &N, &S);
		for (j=1; j<=N; j++)
			scanf("%d", &bulbs[j]);
		answer = min_power(N, S);
		printf("Case #%d\n", i);
		printf("%d\n", answer);
	}

	return 0;
}

