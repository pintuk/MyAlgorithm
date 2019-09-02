#include <stdio.h>
#include <stdint.h>


int is_big_endian(unsigned int x)
{
        int i = 1;

        if (*(char *)&i == 0)
                return 1;

        return 0;
}


/* Convert a 32-bit number from one endian to another */
unsigned int convert32(unsigned int x)
{
        x = ((x & 0xff000000) >> 24) | ((x & 0x000000ff) << 24) |
            ((x & 0x00ff0000) >> 8) | ((x & 0x0000ff00) << 8);

        return x;
}

int main(void)
{
        unsigned int x = 0x12AB34CD;
        unsigned int y;

        printf("original value of x = 0x%x\n", x);
        y = convert32(x);
        printf("after convert, x = 0x%x\n", y);

        return 0;
}
