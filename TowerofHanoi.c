#include <stdio.h>

int count = 0;

void hanoi(int n, int source, int temp, int dest)
{
	if (n <=0) {
		printf("ERROR: Invalid disk....\n");
		return;
	}
	if (n == 1) {
		printf("Move disk from <%c> to <%c>\n", source, dest);
		count++;
		return;
	}
	hanoi(n-1, source, dest, temp);
	//printf("Move disk from <%c> to <%c>\n", source, dest);
	hanoi(1, source, temp, dest);
	hanoi(n-1, temp, source, dest);
}

int main()
{
	int n = 0;
	printf("Enter no. of disks: ");
	scanf("%d",&n);
	hanoi(n, 'A', 'B', 'C');
	printf("Number of moves: %d\n",count);
}

