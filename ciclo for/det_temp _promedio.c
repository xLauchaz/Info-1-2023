#include <stdio.h>
 int main(void){

    int  contador = 0, TAM;
    float promedio, suma = 0, temp;
    printf("Ingrese la cantidad de temperaturas a promediar: ");
    scanf("%d", &TAM);
    for (contador = 0; contador < TAM; contador++)
    {
        printf("Ingrese una temperatura: ");
        scanf("%f", &temp);
        suma += temp;
    }
    printf("El promedio de temperatura es: %.2f\n",promedio = suma / TAM);
    
    return 0;
 }