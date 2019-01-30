#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SIZE	4096
#define PAGE_ALIGN(addr)	(((addr) + (PAGE_SIZE - 1)) & ~(PAGE_SIZE - 1))


int main()
{
	unsigned long c = 0x30;
	unsigned long *addr;
	unsigned long size;

	size = sizeof(unsigned long)*1024;
	addr = (unsigned long *)malloc(size);
	memset(addr, 0, size);
	addr[0] = c;

	printf("BEFORE: addr = %p, *addr = 0x%lx\n", addr, *addr);
	addr = (unsigned long *)PAGE_ALIGN((unsigned long)addr);
	addr[0] = c;
	printf("AFTER PAGE_ALIGN: addr = %p , *addr = 0x%lx\n", addr, *addr);

	return 0;
}
