#include <stdio.h>


#define MAX_LIMIT	300001

int R[MAX_LIMIT];
int visited[MAX_LIMIT];



void reset(int N)
{
	int i;

	for (i=1; i<=N; i++) {
		R[i] = 0;
		visited[i] = 0;
	}
	
}

int find_max(int N, int E[], int visited[])
{
	int i;
	int max = -1;
	int index = 0;

	for (i=1; i<=N; i++) {
		if (!visited[i] && (E[i] > max)) {
			max = E[i];
			index = i;
		}
	}
	return index;
}

void solve(int N, int E[])
{
	int i,r;
	int prev = -1;
	int prevrank = 0;

	//reset(N);
	for (r=1; r<=N; r++) {
		i = find_max(N, E, visited);
		visited[i] = 1;
		if (prev == E[i]) {
			R[i] = prevrank;
			continue;
		}
		R[i] = r;
		prev = E[i];
		prevrank = r;
	}
}

void PrintRank(int N)
{
	int i;

	for (i=1; i<=N; i++) {
		printf("%d ", R[i]);
	}
	printf("\n");
}


int main()
{
	int t,T;
	
	setbuf(stdout, NULL);

	scanf("%d", &T);

	for (t=1; t<=T; t++) {
		int i,N;
		int E[MAX_LIMIT];

		scanf("%d", &N);
		for (i=1; i<=N; i++) {
			scanf("%d", &E[i]);
			visited[i] = 0;
			R[i] = 0;
		}
		solve(N,E);
		printf("Case #%d\n", t);
		PrintRank(N);
	}

	return 0;
}

