#include <stdio.h>
#define TAM 10
void ordenamiento_burbuja(int * const arreglo, const int tamaño);
int main()
{
    int numeros[TAM] = {4,3,7,6,1,5,2,9,10,8};
    printf("numeros orden original\n");
    for (int i = 0; i < TAM; i++)
    {
        printf("%d ",numeros[i]);
    }
    puts("");
    ordenamiento_burbuja(numeros,TAM);
    printf("numeros ordenados\n");
    for (int i = 0; i < TAM; i++)
    {
      printf("%d ",numeros[i]);
    }
    puts("");
    return 0;
}
void ordenamiento_burbuja(int * const arreglo, const int tamaño)
{
    void intercambia(int *ptrElemento1, int *ptrElemento2);
    int pasada;
    int comparaciones;

  for (pasada = 0; pasada < tamaño-1; pasada++)
   {
    for(comparaciones = 0; comparaciones < tamaño-1; comparaciones++)
      {
        if(arreglo[comparaciones] > arreglo[comparaciones+1])
         {
            intercambia(&arreglo[comparaciones],&arreglo[comparaciones+1]);
         }
      }
  }
}
void intercambia(int *ptrElemento1, int *ptrElemento2)
{
  int almacena = *ptrElemento1;
  *ptrElemento1 = *ptrElemento2;
  *ptrElemento2 = almacena;
}