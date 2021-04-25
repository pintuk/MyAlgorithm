#include <stdio.h>


int intersect_point(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, float *px, float *py)
{
	int d = 0;

	d = (x1 - x2)*(y3 - y4) - (y1 - y2)*(x3 - x4);

	printf("value of denominator: %d\n", d);

	*px = ((x1*y2 - x2*y1)*(x3 - x4) - (x3*y4 - x4*y3)*(x1 - x2)) / (float)d;
	*py = ((x1*y2 - x2*y1)*(y3 - y4) - (x3*y4 - x4*y3)*(y1 - y2)) / (float)d;

	return d;
}


int main()
{
	int x1,y1,x2,y2,x3,y3,x4,y4;
	float px, py;
	int d = 0;
	
	printf("Enter co-rodinates of line1(x1,y1,x2,y2): ");
	scanf("%d %d %d %d", &x1,&y1,&x2,&y2);
	printf("Enter co-rodinates of line2(x3,y3,x4,y4): ");
	scanf("%d %d %d %d", &x3,&y3,&x4,&y4);

	d = intersect_point(x1,y1,x2,y2,x3,y3,x4,y4,&px,&py);
	if (d == 0)
		printf("No intersection\n");
	else
		printf("Intersection point: (%3.2f, %3.2f)\n", px, py);

	if ( (px >= x1 && px <= x2) || (px >= x2 && px <= x1) )
		printf("Connected....\n");
	else
		printf("Not connected.\n");

	return 0;
}
