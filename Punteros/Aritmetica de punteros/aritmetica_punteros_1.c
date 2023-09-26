#include <stdio.h>

int main(void){

    int numero = 10;
    int* pnum;

    pnum = &numero;

    printf("%d\n", *pnum);
    printf("%d\n", numero);
    printf("%p\n", pnum);
    printf("%p\n", &numero);

    return 0;
}