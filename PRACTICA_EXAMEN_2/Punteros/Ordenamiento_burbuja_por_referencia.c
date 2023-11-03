#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TAM 10000
void ordenaMBurbuja(int *const arreglo, const int tamaño);

int main()
{
    int a[TAM] = {0};
    int i;
    srand(time(NULL));
    for (i = 0; i < TAM; i++)
    {
        a[i] = rand() % 100;
    }
    
    printf("Elementos de datos en el orden original\n");
    for ( i = 0; i < TAM; i++)
    {
        printf("%4d", a[i]);
    }
    ordenaMBurbuja(a,TAM);
    printf("\nElementos de datos ordenados\n");
    for ( i = 0; i < TAM; i++)
    {
        printf("%4d",a[i]);
    }
    printf("\n");
    return 0;
}
void ordenaMBurbuja(int * const arreglo, const int tamaño)
{
    void intercambia( int *ptrElemento1, int *ptrElemento2);
    int pasada;
    int j;

    for (pasada  = 0; pasada < tamaño; pasada++)
    {
        for (j = 0; j < tamaño - 1; j++)
        {
            if (arreglo[j] > arreglo[j +1])
            {
                intercambia(&arreglo[j],&arreglo[j+1]);
            }
            
        }
        
    }
    
}
void intercambia(int *ptrElemento1, int *ptrElemento2)
{
    int almacena = *ptrElemento1;
    *ptrElemento1 = *ptrElemento2;
    *ptrElemento2 = almacena;
}