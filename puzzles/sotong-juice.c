#include <stdio.h>

#define MIN(a,b)	(((a) < (b)) ? (a) : (b))
#define INFINITY	(999999)

struct Juice {
	int price;
	int weight;
} juice[501];

int Table[501];

int solve(int N, int W)
{
	int i,j;

	//for (i=0; i<=N; i++) {
	//	Table[i][0] = 0;
	//}
	Table[0] = 0;
	for (j=1; j<=W; j++) {
		Table[j] = INFINITY;
	}

	for (i=1; i<=N; i++) {
		for (j=1; j<=W; j++) {
			if (j >= juice[i].weight)
				Table[j] = MIN(Table[j], Table[j - juice[i].weight] + juice[i].price);
		}
	}
	return Table[W];
}

void reset(int N, int W)
{
	int i,j;

	for (i=0; i<=N; i++) {
		juice[i].price = 0;
		juice[i].weight = 0;
	}
	//for (i=0; i<=N; i++) {
		for (j=0; j<=W; j++) {
			Table[j] = INFINITY;
		}
	//}
}

int main()
{
	int t,ncases;

	setbuf(stdout, NULL);
	scanf("%d", &ncases);
	for (t=1; t<= ncases; t++) {
		int i,E,F,N;
		int ret = 0;

		scanf("%d %d", &E, &F);
		scanf("%d", &N);
		reset(N, (F-E));
		for (i=1; i<=N; i++) {
			scanf("%d %d", &juice[i].price, &juice[i].weight);
		}
		ret = solve(N, (F-E));
		if (ret == INFINITY)
			printf("%s\n", "impossible");
		else
			printf("%d\n", ret);
	}	
}

