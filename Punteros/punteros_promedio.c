#include <stdio.h>
#define TAM 10
// Modificar este programa para ordenar el arreglo de mayor a menor.

void cargar_elementos(int *arreglo, int tam)
{
  for (int i = 0; i < tam; i++)
  {
    printf("Ingrese nota: ");
    scanf("%d", &arreglo[i]);
  }
}

void imprimir_elementos(int *arreglo, int tam){
  for (int i = 0; i < tam; i++)
  {
    printf("%d\n", arreglo[i]);
  }
}
void ordenamiento(int *arreglo, int tam){
    int aux;
    for (int i = 0; i < tam-1; i++)
    {
        for (int j = i+1; j < tam; j++)
        {
            if (arreglo[i]>arreglo[j])
            {
                aux = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = aux;
            }
        }
    }
}
//funcion que calcula el promedio de un arreglo tamaño tam
float promedio(int *a, int tam){
    float prom = 0;
    for (int i = 0; i < tam; i++)
    {
        prom += a[i];
    }
    return prom/tam;
}
//funcion que calcula la mediana de un arreglo tamaño tam
int mediana(int *a, int tam){
    return a[tam/2];
}
int main(void){
  int nota[TAM];
  cargar_elementos(nota,TAM);
  ordenamiento(nota,TAM);
  imprimir_elementos(nota,TAM);
    printf("El promedio es: %.2f\n", promedio(nota,TAM));
    printf("La mediana es: %d\n", mediana(nota,TAM));
  return 0;
}