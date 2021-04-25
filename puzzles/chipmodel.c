#include <stdio.h>

int N,C,M,B,cp,mp;
int Model[1001][4];


int solve()
{
	int i,j,k;
	int maxvalue = -1;
	
	maxvalue = C*cp + M*mp;

	
}


int main()
{
	int t, ncases;

	scanf("%d", &ncases);
	for (t=1; t<=ncases; t++) {
		int i,j;
		int Answer = 0;

		scanf("%d %d %d %d %d", &C,&M,&B,&cp,&mp);
		scanf("%d", &N);
		for (i=1; i<=N; i++) {
			for (j=1; j<=4; j++) {
				scanf("%d", &Model[i][j]);
			}
		}
		Answer = solve();
		printf("#%d %d\n", t, Answer);
	}
	return 0;
}
