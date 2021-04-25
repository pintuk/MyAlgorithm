#include <stdio.h>

int N,M;
char grid[201][201];
int temp[201][201];


int is_same(int x1, int y1, int x2, int y2)
{
	int i,j;

	for (i=x1; i<=x2; i++) {
		for (j=y1; j<=y2; j++) {
			if (grid[i][j] != grid[x1][y1])
				return 0;
		}
	}
	return 1;
}

int solve()
{
	int x1,x2,y1,y2;
	int i,j;
	int count = 0;

	for (x1=1; x1<=N; x1++) {
		for (y1=1; y1<=M; y1++) {
			for (x2=x1; x2<=N; x2++) {
				for (y2=y1; y2<=M; y2++) {
					int flag = 0;

					if (temp[x2][y2] == 1)
						continue;
					if ((x1 != x2) && (x1 == y2) && (x2 == y1))
						continue;
					flag = is_same(x1,y1,x2,y2);
					if (flag == 0)
						continue;
					count++;
				}
			}
			temp[x1][y1] = 1;
		}
	}
	return count;
}

int main()
{
	int t,T;

	//freopen("sample_input_jewels.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (t=1; t<=T; t++) {
		int i,j;
		char color[201];
		int Answer = 0;

		scanf("%d %d", &N, &M);
		for (i=1; i<=N; i++) {
			scanf("%s", color);
			for (j=1; j<=M; j++) {
				grid[i][j] = color[j-1];
				temp[i][j] = 0;
			}
		}
		Answer = solve();
		printf("#%d %d\n", t, Answer);
	}
	return 0;
}

