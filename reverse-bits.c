#include <stdio.h>
#include <stdint.h>

uint32_t reverse_bits(uint32_t x)
{
        x = (x >> 16) | (x << 16);
        x = ((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8);
        x = ((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4);
        x = ((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2);
        x = ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1);

        return x;
}

int main()
{
        uint32_t x;

        x = 0x12AB34CD;
        printf("original value: 0x%x\n", x);
        x = reverse_bits(x);
        printf("After reverse bits, value: 0x%x\n", x);

        return 0;
}
