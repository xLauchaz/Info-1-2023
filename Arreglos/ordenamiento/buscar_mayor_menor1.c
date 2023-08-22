#include <stdio.h>
#include <time.h>
#define TAM 10
int main(int argc, char const *argv[])
{   
    int arreglo[TAM];
    int mayor, menor;
    srand(time(NULL));
    for (int i = 0; i <TAM; i++)
    {
        arreglo[i] = rand()%10001;
    }
    mayor = menor = arreglo[0];
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
