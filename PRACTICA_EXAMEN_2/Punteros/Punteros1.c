#include <stdio.h>

int main()
{
    int a;
    int *ptrA;
    a = 7;
    ptrA = &a;
    printf("La direccion de a es %p""\nEl valor de ptrA es %p", &a,ptrA);
    printf("\nEl valor de a es %d""\nEl valor de ptrA es %p", a,*ptrA);
    
    return 0;
}