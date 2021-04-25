#include <stdio.h>

int N=10;
int K;
int fare[1000];
int cost[1000];

#define MIN(a,b)        ((a) < (b) ? (a) : (b))
#define INFINITY	99999


void reset()
{
    int i;
    for (i=0; i<=1000; i++) {
        fare[i] = 0;
        cost[i] = INFINITY;
    }
}

void PrintCost()
{
	int i;

	for (i=1; i<=K; i++)
		printf("%5d ", cost[i]);
	printf("\n");
}

int solve()
{
    int i,j;

    cost[0] = 0;
    for (j=1; j<=K; j++) {
        for (i=1; i<=N; i++) {
            if (i > j) break;
            cost[j] = MIN(cost[j], cost[j-i] + fare[i]);
	    //PrintCost();
        }
    }
    return cost[K];
}

int main(void)
{
        int tc, T;

        setbuf(stdout, NULL);

        scanf("%d", &T);
        for(tc = 0; tc < T; tc++)
        {
                int i;
        int Answer = 0;

	reset();
        for (i=1; i<=N; i++)
            scanf("%d", &fare[i]);
        scanf("%d", &K);

        Answer = solve();
        printf("%d\n", Answer);
        }

        return 0;
}
