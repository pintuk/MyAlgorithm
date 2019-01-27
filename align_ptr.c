#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SIZE	4096
#define PAGE_ALIGN(addr)	(((addr) + (PAGE_SIZE - 1)) & ~(PAGE_SIZE - 1))


int main()
{
	unsigned long c = 0x30;
	unsigned long *addr;

	addr = (unsigned long *)malloc(sizeof(unsigned long)*100);
	memset(addr, 0, sizeof(unsigned long)*1024);
	addr[0] = c;

	printf("BEFORE: addr = %p, *addr = 0x%lx\n", addr, *addr);
	addr = (unsigned long *)PAGE_ALIGN((unsigned long)addr);
	addr[0] = c;
	printf("AFTER PAGE_ALIGN: addr = %p , *addr = 0x%lx\n", addr, *addr);

	return 0;
}
