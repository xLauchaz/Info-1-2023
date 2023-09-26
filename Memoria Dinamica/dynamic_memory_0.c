#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *parreglo;

    parreglo = malloc(1*sizeof(int));
    *parreglo = 10;

    printf("%d\n", *parreglo);

    return 0;
}