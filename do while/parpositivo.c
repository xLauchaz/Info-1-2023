#include <stdio.h>

int main(void){
    int num;
    do
    {
        printf("Ingrese un numero positivo: ");
        scanf("%d", &num);
        if (num % 2 == 0)
        {
            printf("El numero es par\n");
        }
        else
        {
        
            printf("El numero es impar\n");
        }
        
    } while (num != 0);
    return 0;
}