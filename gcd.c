#include <stdio.h>


int gcd(int x, int y)
{
	int temp; int r = 0;

	if (y == 0) {
		return x;
	}
	if (x < y) {
		temp = x;
		x = y;
		y = temp;
	}
	printf("x: %d, y:%d\n",x,y);
	r = x%y;
	x = y;
	y = r;
	return gcd(x, y);
}

int main()
{
	int value=0;
	int x,y;

	printf("Enter two numbers: ");
	scanf("%d%d",&x,&y);
	value = gcd(x, y);
	printf("GCD of <%d> and <%d> = %d\n",x,y,value);
}

