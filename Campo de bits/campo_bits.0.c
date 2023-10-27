#include <stdio.h>

typedef struct 
{
    unsigned char b0:4; // :4 declara que tiene 4 bits
    unsigned char b1:8;
    unsigned char b2:8;
    unsigned char b3:6;
}campo_bits;

int main(void)
{
    campo_bits mis4bits;
    mis4bits.b0 = 15;
    mis4bits.b1 = 0;
    mis4bits.b2 = 1;
    mis4bits.b3 = 1;

    printf("%u %u %u %u\n",mis4bits.b0,mis4bits.b1,mis4bits.b2,mis4bits.b3);
}