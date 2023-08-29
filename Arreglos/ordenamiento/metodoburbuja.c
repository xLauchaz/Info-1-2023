#include <stdio.h>
#define N 5
/*int main(void){
    int a[N]={41,23,346,76,9};
    int i,j;
    for ( i = 0; i < N; i++)
    {
        for(j=0;j<N-1;j++){ //J llega hasta N-1 para evitar salir del arreglo
            if(a[j]>a[j+1]){
                int aux=a[j];
                a[j]=a[j+1];
                a[j+1]=aux;
            }
        }
    }
    return 0;
}
*/
int main(void){
    int a[N]={41,23,346,76,9};
    int i,j;
    for ( i = 0; i < N; i++)
    {
        for(j=0;j<N-1-i;j++){ /*J llega hasta N-1-i para evitar salir del arreglo*/
            if(a[j]>a[j+1]){
                int aux=a[j];
                a[j]=a[j+1];
                a[j+1]=aux;
            }
        }
    }
    return 0;
}