#include <stdio.h>

int main(void)
{
    int a = 20;
    int *ptra;

    ptra = &a;

    printf("El valor de a es: %d\n", a);
    printf("El valor del puntero de a es: %p\n", ptra);
    printf("Si desreferenciamos ptra nos da: %d\n", *ptra);
    return 0;
}