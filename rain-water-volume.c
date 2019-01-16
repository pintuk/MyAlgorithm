#include <stdio.h>

#define MAX(a, b)	((a) > (b) ? (a) : (b))
#define MIN(a, b)	((a) < (b) ? (a) : (b))

int heights[100005];
int N;

int *find_leftmax(void)
{
	int i;
	int max;
	static int leftmax[100005];

	max = heights[0];
	for (i = 0; i < N; i++) {
		if (heights[i] > max)
			max = heights[i];
		leftmax[i] = max;
	}

	return leftmax;
}

int *find_rightmax(void)
{
	int i;
	int max;
	static int rightmax[100005];

	max = heights[N - 1];
	for (i = N - 1; i >= 0; i--) {
		if (heights[i] > max)
			max = heights[i];
		rightmax[i] = max;
	}

	return rightmax;
}

int volume(void)
{
	int i;
	int *leftmax = NULL;
	int *rightmax = NULL;
	int min, sum;

	leftmax = find_leftmax();
	rightmax = find_rightmax();
	sum = 0;
	for (i = 0; i < N; i++) {
		min = MIN(leftmax[i], rightmax[i]);
		//printf("left: %d, right: %d, min: %d\n", leftmax[i], rightmax[i], min);
		sum += min - heights[i];
	}

	return sum;
}

int main()
{
	int i;
	int answer = 0;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &heights[i]);

	answer = volume();
	printf("%d\n", answer);

	return 0;
}
