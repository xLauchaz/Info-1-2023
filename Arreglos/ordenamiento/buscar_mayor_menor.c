#include <stdio.h>
#include <time.h>
#define TAM 10
/* buscar el mayor y el menor*/
int main(void){

    int arreglo[TAM];
    int mayor, menor;

    for (int i = 0; i <TAM; i++)
    {
        printf("Ingrese un numero a almacenar: ");
        scanf("%d",&arreglo[i]);
    }
    mayor = arreglo[0];
    menor = arreglo[0];
    for (int i = 0; i < TAM; i++)
    {
        if (arreglo[i]>mayor)
        {
            mayor = arreglo[i];
        }
        if (arreglo[i]<menor)
        {
            menor = arreglo[i];
        }
    }
    printf("El mayor es %d y el menor es %d\n",mayor,menor);
    
    

    return 0;
}