#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int tam;
    int *parreglo;

    do
    {
        printf("Ingrese eñ tamaño del arreglo: ");
        scanf("%d", &tam);
    } while (tam <= 0);
    
    parreglo = malloc(tam * sizeof(int));
    return 0;
}