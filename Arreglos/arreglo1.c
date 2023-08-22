#include <stdio.h>
#define N 5
/*solicitar al usuario 10 numeros enteros, los almacane en un arreglo.Luego se debe recorrer el arreglo convirtiendo los numeros
negativos en positivos. por ultimo mostrar en la pantalla el arreglo*/
int main(void){

    int i;
    int a[N];
    int b[N];
    for ( i = 0; i < N; i++)
    {
        printf("Ingrese la nota %d: ", i+1);
        scanf("%d", &a[i]);

    }
    for ( i = 0; i < N; i++)
    {
        printf("Ingrese la nota %d: ", i+6);
        scanf("%d", &b[i]);
    }
    
    for ( i = 0; i < N; i++)
    {
        if (a[i] < 0)
        {
            a[i] = -a[i];
        }
        
    }
    for ( i = 0; i < N; i++)
    {
        if (b[i] < 0)
        {
            b[i] = -b[i];
        }
        
    }
    for ( i = 0; i < N; i++)
    {
        printf("La nota %d es: %d\n", i+1, a[i]);
    }
    for ( i = 0; i < N; i++)
    {
        printf("La nota %d es: %d\n", i+1, b[i]);
    }
    return 0;
}