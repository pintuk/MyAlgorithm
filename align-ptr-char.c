#include <stdio.h>


#define ALIGN(x,a)      (((x) + ((a) - 1)) & ~((a) - 1))


void * align_pointer(char *p)
{
        p = (char *)ALIGN((unsigned long)p, 4096);
        //printf("align_pointer:  address of p = %p, value of p: 0x%x\n", p, *p);
        return p;
}

int main()
{
        char *p;
        char x = 0x30;
        p = &x;
        printf("BEFORE: address of p = %p, value of p: 0x%x\n", p, *p);
        p = (char *)align_pointer(p);
        *p = x;
        printf("AFTER:  address of p = %p, value of p: 0x%x\n", p, *p);

        return 0;
}
