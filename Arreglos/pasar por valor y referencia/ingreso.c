#include <stdio.h>
#define TAM 10
void ingresar_elemento(int a[], int tam);//aca no se pasa el arreglo, sino la direccion del primer elemento del mismo.
void imprimir_arreglo(int a[], int tam);
float calcular_promedio(int a[], int tam);
//funcion que solicita ingresar un numero en el rango de 0 - 100
int ingreso_y_validacion(void);
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
        a[i]=ingreso_y_validacion();
    }
}
int ingreso_y_validacion(void){
    int n;
    do
    {
        printf("Ingrese un numero entre 0 - 100: ");
        scanf("%d", &n);
        if (n < 0 || n > 100)
        {
            printf("El numero no esta dentro de el rango permitido\n");
        }
    } while (n < 0 || n > 100);
    return n;
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