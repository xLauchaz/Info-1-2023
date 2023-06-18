#include <stdio.h>
int main(void){

    int n;
    do
    {
        printf("Ingrese un numero entre 0 y 100: ");
        scanf("%d", &n);
        if (n < 0 || n > 100)
            printf("El numero ingresado no esta dentro del rango propuesto\n");
    } while (n < 0 || n > 100);
    
    return 0;
}