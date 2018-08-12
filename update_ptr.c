#include <stdio.h>

void update_pointer(unsigned int *p, unsigned int c)
{
	unsigned int q;
	int pos = 17;
	int n = 2;

	//*p = *p & ~(1 << 17);
	//*p = *p & ~(1 << 18);
	q = ~((~(~0UL << n)) << pos);
	*p = *p & q;
	*p = *p | (c << 17);
}

int main()
{
	unsigned int x = 0x3f4a5b;
	unsigned char c = 0x02;
	printf("Before: x = 0x%x\n", x);
	update_pointer(&x, c);
	printf("After:  x = 0x%x\n", x);
	return 0;
}
