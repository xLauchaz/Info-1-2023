#include <stdio.h>
#define TAM 10
void ingresar_elemento(int a[], int tam);
void imprimir_arreglo(int a[], int tam);
float calcular_promedio(int a[], int tam);
int main(void){
    int arreglo[TAM];
    ingresar_elemento(arreglo, TAM);
    imprimir_arreglo(arreglo, TAM);
    float promedio = calcular_promedio(arreglo,TAM);
    printf("El primedio es: %f\n", promedio);
    return 0;
}
void ingresar_elemento(int a[], int tam){
    for(int i = 0; i < tam; i++){
        printf("Ingrese el elemento %d: ", i);
        scanf("%d", &a[i]);
    }
}
void imprimir_arreglo(int a[], int tam){
    for(int i = 0; i < tam; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
float calcular_promedio(int a[], int tam){
    float suma = 0;
    for(int i = 0; i < tam; i++){
        suma += a[i];
    }
    return suma/tam;
}