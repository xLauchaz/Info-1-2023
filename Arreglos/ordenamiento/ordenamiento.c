#include <stdio.h>
int main(int argc, char const *argv[])
{
    int arreglo[]={89,22,9,4,13,3,73,10};
    int aux;
    for (int i = 0; i < 8; i++)
    {
        printf("%d ",arreglo[i]);
    }
    printf("\n");
    for (int i = 0; i < 8; i++)
    {
        for (int j = i+1; j < 8; j++)
        {
            if (arreglo[i]>arreglo[j])
            {
                aux = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = aux;
            }
        }
    }
    for (int i = 0; i < 8; i++)
    {
        printf("%d ",arreglo[i]);
    }
    return 0;
}
