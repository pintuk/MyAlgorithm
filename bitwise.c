#include <stdio.h>

unsigned int setbits(unsigned int x, int p, unsigned int y, int n)
{
	unsigned int mask, clear, set;

	//~0 = 1111 1111
	// ~0 << n => 1111 0000
	//~(~0 << n) => 0000 1111
	// That is; first n bits are set to all 1s
	mask = ~(~0UL << n);

	//before setting the bits, first we need to clear those bits
	//mask << p => 0111 1000
	//~(mask << p) => 1000 0111
	//TThus with the below operation, 4 bits will be 0, from position p
	clear = x & ~(mask << p);

	//not get n bits of y, and move at position p
	set = (mask & y) << p;

	//therefore
	x = clear | set;

	return x;
}

//invert n bits of x at position p
unsigned int invertbits(unsigned int x, int p, int n)
{
	unsigned int mask;

	mask = ~(~0UL << n);
	x = x ^ (mask << p);

	return x;
}

//get n bits of x as position p

unsigned int getbits(unsigned int x, int p, int n)
{
	unsigned int mask;

	mask = ~(~0UL << n);
	x = x & (mask << p);
	x = x >> p;

	return x;
}

unsigned int rotate_bits(unsigned int x)
{
	int n = 16;
	x = ((x & 0x0000ffff) << 16) | ((x & 0xffff0000) >> 16);

	return x;
}

int main()
{
	//unsigned int x = 0x7f3b5a;
	unsigned int x = 0x45;
	unsigned int y = 0x7a;
	unsigned int value;
	int p, n;

	printf("x = 0x%x ; y = 0x%x\n", x, y);
	printf("Enter position, and no. of bits to set:\n");
	scanf("%d %d", &p, &n);
	value = setbits(x, p, y, n);
	printf("After setbits: value of x now: 0x%x\n", value);
	value = invertbits(x, p, n);
	printf("After invertbits: value of x now: 0x%x\n", value);
	value = getbits(x, p, n);
	printf("After getbits: value of x now: 0x%x\n", value);

	value = rotate_bits(x);
	printf("After reverse_bits: value of x now: 0x%x\n", value);

	return 0;
}
