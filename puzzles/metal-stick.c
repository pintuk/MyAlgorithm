#include <stdio.h>

#define MAX(a,b)	((a) > (b) ? (a) : (b))

int N;

struct MetalStick {
	int front;
	int back;
} Stick[100];

int visited[100];

int solve(int i, int front, int back, int count)
{
	int maxvalue = 0;

	if (i == N) {
		if (count > maxvalue)
			maxvalue = count;
			return maxvalue;
	}

	printf("i: %d, front: %d, back: %d, count: %d\n", i,front,back,count);
	
	//for (i=1; i<=N; i++) 
	{
		if (front == Stick[i].front && !visited[i]) {
			front = Stick[i].back;
			back = back;
			visited[i] = 1;
			solve(i+1, front, back, count+1);
			visited[i] = 0;
		}
		else if (back == Stick[i].back && !visited[i]) {
			front = front;
			back = Stick[i].front;
			visited[i] = 1;
			solve(i+1, front, back, count+1);
			visited[i] = 0;
		}
		else if (front == Stick[i].back && !visited[i]) {
			front = Stick[i].front;
			back = back;
			visited[i] = 1;
			solve(i+1, front, back, count+1);
			visited[i] = 0;
		}
		else if (back == Stick[i].front && !visited[i]) {
			back = Stick[i].back;
			front = front;
			visited[i] = 1;
			solve(i+1, front, back, count+1);
			visited[i] = 0;
		}
		else {
			visited[i] = 1;
			solve(i+1, front, back, count);
			visited[i] = 0;
		}
	}
	
	return maxvalue;
}

int main()
{
	int t,T;

	scanf("%d", &T);
	for (t=1; t<=T; t++) {
		int i;
		int Answer = 0;
		int front,back;

		scanf("%d", &N);
		for (i=1; i<=N; i++) {
			scanf("%d %d", &Stick[i].front, &Stick[i].back);
			visited[i] = 0;
		}
		front = Stick[1].front;
		back = Stick[1].back;
		Answer = solve(1,front,back,0);
		printf("#%d %d\n", t, Answer);
	}

	return 0;
}

