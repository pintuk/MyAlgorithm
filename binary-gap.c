#include <stdio.h>

int solution(int N) {
    // write your code in C99 (gcc 6.2.0)
    int max = 0;
    int c = 0;
    int flag = 0;
    
    while (N > 0) {
        if ((N & 01) == 1) {
            c = 0;
            flag = 1;
        }
        else {
            if (flag == 1) {
                c++;
                if (c > max)
                    max = c;
            }
        }
        N = N >> 1;
    }
    return max;
}

int main()
{
	int N;
	int Answer = 0;

	printf("Enter a number: \n");
	scanf("%d", &N);
	printf("Hex of number = 0x%x\n", N);
	Answer = solution(N);
	printf("Max gap of zeros = %d\n", Answer);

	return 0;
}
