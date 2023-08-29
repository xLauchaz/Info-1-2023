#include <stdio.h>
#define N 10
int main(void){
    int a[N];
    int i,j,aux;
    for ( i = 0; i < N; i++)
    {
        printf("Ingrese el numero a ordenar: ");
        scanf("%d",&a[i]);
    }
    
    for ( i = 0; i < N; i++)
    {
        for ( j = 0; j < N-1; j++)
        {
            if (a[j]<a[j+1])
            {
                aux = a[j];
                a[j]=a[j+1];
                a[j+1]=aux;
            }
            
        }
        
    }
    for ( i = 0; i < N; i++)
    {
        printf("%d\n",a[i]);
    }
    printf("El mayor elemento es a[0]=%d\n",a[0]);
    
    return 0;
}
