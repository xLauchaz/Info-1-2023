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
int main(void) {
  int nota[TAM];
  cargar_elementos(nota,TAM);
  ordenamiento(nota,TAM);
  imprimir_elementos(nota,TAM);
  return 0;
}