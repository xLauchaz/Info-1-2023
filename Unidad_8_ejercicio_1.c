#include <stdio.h>
#define N 10
void swap(int * a, int * b);
void validar_positividad(int * a);
void validar_no_primo(int * a);
int main(void){

    int arreglo[N];
    validar_positividad(arreglo);
    validar_no_primo(arreglo);
    for(int i = 0; i < N; i++)
    {
        printf("%d ", arreglo[i]);
    }
    swap(&arreglo[0], &arreglo[N-1]);
    printf("\n");
    for(int i = 0; i < N; i++)
    {
        printf("%d ", arreglo[i]);
    }
    return 0;
}
void validar_positividad(int * a)
{
    for(int i = 0; i < N; i++)
    {
        printf("Ingrese un valor positivo: ");
        scanf("%d", &a[i]);
        if (*(a+i) < 0 || *(a+i) > 100 )
        {
            --i;   
        }
        
    }
}
void validar_no_primo(int * a)
{
    int primo = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 1; j <= *(a+i); j++)
        {
            if (*(a+i) % j == 0)
            {
                primo++;
            }
        }
        if (primo != 2)
        {
           ++(*(a+i));
        }
        primo = 0;
    }
    
}
void swap(int * a, int * b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}