#include <stdio.h>
//determinar el mayor numero ingresado
int main(void){
    int num, mayor= 0, contador = 0, Max;
    printf("Ingrese la nota maxima posible: ");
        scanf("%d", &Max);
    while (contador < 10){   
        printf("Ingrese un numero: ");
        scanf("%d", &num);

        if(num > 0 && num < Max){
            if (num > mayor)
            {
            mayor = num;
            }
            else{
            printf("\n");
            }
        contador +=1;
        }
    }
    printf("El mayor numero ingresado es: %d\n", mayor);
    
    return 0;   
}