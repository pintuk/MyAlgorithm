#include <stdio.h>


#define SWAP(a, b)      do { \
                                int t; \
                                t = a; \
                                a = b; \
                                b = t; \
                        } while (0)


int main()
{
        int i, N;
        int A[] = {8, 7, 4, 2, 1, 5};

        N = 6;
        for (i = 0; i < N/2; i++)
                SWAP(A[i], A[N - i - 1]);

        for (i = 0; i < N; i++)
                printf("%d ", A[i]);
        printf("\n");

        return 0;
}
