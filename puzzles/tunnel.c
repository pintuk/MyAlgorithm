#include <stdio.h>

#define MIN(a,b)	((a) < (b) ? (a) : (b))
#define INFINITY	(999999999)
#define ABS(x)		((x) < 0 ? (-x) : (x))

int N,H,V;
int C1,R1,M1,C2,R2,M2;
int S[20][501];

int Table[50000][20];
int A[20];
int L = 0;

void store_result(int *A, int n)
{
        int i;

        for (i=0; i<n; i++)
                Table[L][i] = A[i];
        L++;
}

void combine_using_for_loop(int num, int N)
{
        int a,b,c,d,e;

        for (a=1; a<=num; a++) {
                for (b=1; b<=num; b++) {
                        if (N == 2) {
                                A[0] = a; A[1] = b;
                                store_result(A, N);
                        }
                        for (c=1; c<=num; c++) {
                                if (N == 3) {
                                        A[0] = a; A[1] = b; A[2] = c;
                                        store_result(A, N);
                                }
                                for (d=1; d<=num; d++) {
                                        if (N == 4) {
                                                A[0] = a; A[1] = b; A[2] = c; A[3] = d;
                                                store_result(A, N);
                                        }
                                        for (e=1; e<=num; e++) {
                                                //printf("{%d, %d, %d, %d, %d}\n", a,b,c,d,e);
                                                //L++;
                                                if (N == 5) {
                                                        A[0] = a; A[1] = b; A[2] = c; A[3] = d; A[4] = e;
                                                        store_result(A, N);
                                                }
                                        }
                                }
                        }
                }
        }
}

void PrintTable()
{
	int i,j;

	printf("=============================\n");
	for (i=0; i<L; i++) {
		for (j=0; j<H; j++) {
			printf("%d ", Table[i][j]);
		}
		printf("\n");
	}
	printf("=============================\n");
}

int solve()
{
	int i,j,k;
	int min = INFINITY;
	int prev = 0;
	int Marray[20];

	L = 0;
	combine_using_for_loop(2, H);
	//PrintTable();

	for (k=0; k<V; k++) {
		min = INFINITY;
		for (i=0; i<L; i++) {
			int minval = 0;
			int h = H-1;
			int v = 0;
			prev = 0;
			for (j=0; j<H; j++) {
				int E = Table[i][j];

				if (E != prev) {
					if (E == 1) {
						minval = minval + S[k][v]*C1;
						//printf("E: %d, C1: %d, S[%d][%d]: %d, minval: %d\n", E, C1, k, v, S[k][v], minval);
						v++;
					} else {
						minval = minval + S[k][h]*C2;
						//printf("H: %d, j: %d, h : %d\n", H,j,h);
						//printf("E: %d, C2: %d, S[%d][%d]: %d, minval: %d\n", E, C2, k, h, S[k][h], minval);
						h--;
					}
				} else {
					if (E == 1) {
						minval = minval + ((S[k][v]*C1) + R1);
						//printf("E: %d, C1: %d, R1: %d, S[%d][%d]: %d, minval: %d\n", E, C1, R1, k, v, S[k][v], minval);
						v++;
					} else {
						minval = minval + ((S[k][h]*C2) + R2);
						//printf("H: %d, j: %d, h : %d\n", H,j,h);
						//printf("E: %d, C2: %d, R2: %d, S[%d][%d]: %d, minval: %d\n", E, C2, R2, k, h, S[k][h], minval);
						h--;
					}
				}
				prev = E;
				//if (j > H || h < 0)
				//	break;
			}
			//printf("----------------------------\n");
			if (minval < min)
				min = minval;
		}
		//printf("min: %d\n", min);
		Marray[k] = min;
	}
	if (V > 1) {
		L = 0;
		combine_using_for_loop(4, N);
		min = INFINITY;
		for (i=0; i<L; i++) {
			int prev = Table[i][0];
			for (j=1; j<N; j++) {
				int E = Table[i][j];
				int D = ABS(E - prev);
				int minval = 0;

				if ( D >= 2) {
					minval = Marray[prev-1] + (M1*M1 + M2*M2)*D + Marray[E-1];
					//printf("prev: %d, E: %d, D: %d\n", prev, E, D);
					if (minval < min)
						min = minval;
				}
				//printf("MIN : %d\n", min);
				prev = E;
			}
		}
	}

	return min;
}


int main()
{
	int t,T;

	setbuf(stdout, NULL);

	scanf("%d", &T);

	for (t=1; t<=T; t++) {
		int i,j;
		int Answer = -1;

		scanf("%d %d %d", &N,&H,&V);
		for (i=0; i<V; i++) {
			for (j=0; j<H; j++) {
				scanf("%d", &S[i][j]);
			}
		}
		scanf("%d %d %d", &C1,&R1,&M1);
		scanf("%d %d %d", &C2,&R2,&M2);
		Answer = solve();
		printf("Case #%d\n%d\n", t, Answer);
	}

	return 0;
}
