#include <stdio.h>
#define TAM 10
int main(int argc, char const *argv[])
{
    int arreglo[TAM]={89,22,9,4,13,3,73,10,25,100};
    int aux;
    for (int i = 0; i < TAM; i++)
    {
        printf("%d ",arreglo[i]);
    }
    printf("\n");
    for (int i = 0; i < TAM; i++)
    {
        for (int j = i+1; j < TAM-1; j++)
        {
            if (arreglo[i]>arreglo[j])
            {
                aux = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = aux;
            }
        }
    }
    for (int i = 0; i < TAM; i++)
    {
        printf("%d ",arreglo[i]);
    }
    return 0;
}
