#include <stdio.h>

#define ALIGN(x,a)	(((x) + ((a) - 1)) & ~((a) - 1))
#define PAGE_SIZE	4096

char *align_pointer(char *p)
{
	p = (char *)ALIGN((unsigned long)p, PAGE_SIZE);
	return p;
}

int main()
{
	unsigned char c = 0x30;
	char *p = (char *)&c;

	printf("BEFORE: p = %p, *p = 0x%x\n", p, *p);
	p = align_pointer(p);
	printf("BEFORE: p = %p, *p = 0x%x\n", p, *p);

	return 0;
}
