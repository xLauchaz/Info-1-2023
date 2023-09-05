#include <stdio.h>
#define TAM 10
void ingresar_elemento(int a[], int tam){
   for (int i = 0; i < tam; i++)
   {
        printf("Ingrese el número: ");
        scanf("%d",&a[i]);
   }
   
}
int main(void){
    int arreglo[TAM];
    ingresar_elemento(arreglo, TAM);
    printf("El elemento vale %d\n", arreglo[0]);
    return 0;
}