#include <stdio.h>
#define TAM 3

/** Función para sumar arreglos
  * operación:  c = a + b
  *  */
void imprimir_resultados(float* arreglo_a, float* arreglo_b, float* arreglo_c, const int tam);
void sumar_arreglos(float* arreglo_c, const float* arreglo_a, const float* arreglo_b, const int tam)
{
  for (int i = 0; i < tam; i++){
    *(arreglo_c+i) = *(arreglo_a+i) + *(arreglo_b+i);
  }
  
}

void cargar_arreglo(float* arreglo_c, const int tam)
{
  for (int i = 0; i < tam; i++){
    printf("Ingrese el elemento %d: ", i);
    scanf("%f", arreglo_c+i);
  }
}
/** Función para multiplicar arreglos elemento a elemento
  * operación:  c[i] = a[i] * b[i]
  *  */

void multiplicar_arreglos(float* arreglo_c, const float* arreglo_a, const float* arreglo_b, const int tam)
{
    for(int i = 0; i < tam; i++)
    {
        *(arreglo_c+i) = *(arreglo_a+i) * *(arreglo_b+i);
    }
}
float producto_punto(float* arreglo_a, const float* arreglo_b, const int tam)
{
    float resultado = 0;
    for(int i = 0; i < tam; i++)
    {
        resultado += *(arreglo_a+i) * *(arreglo_b+i);
    }
    return resultado;
}
void imprimir_resultados(float* arreglo_a, float* arreglo_b, float* arreglo_c, const int tam)
{
  static int a = 0;
    printf("Resultados ");
    if(a == 0)
    {   
      printf("suma:\n");
        for(int i = 0; i < tam; i++)
        {
            printf("%f + %f = %f\n", arreglo_a[i], arreglo_b[i], arreglo_c[i]);
        }
        a++;
    }
    else if(a == 1)
    {
      printf("multiplicación:\n");
        for (int i = 0; i < tam; i++)
        {
            printf("%f * %f = %f\n", arreglo_a[i], arreglo_b[i], arreglo_c[i]);
        }
        a++;
    }
    else if(a == 2)
    {
        printf("Producto punto: %f\n", producto_punto(arreglo_a, arreglo_b, tam));
    }
}
int main(void) {

  float a[TAM], b[TAM], c[TAM];

  cargar_arreglo(a, TAM);
  cargar_arreglo(b, TAM);
  sumar_arreglos(c, a, b, TAM);
  imprimir_resultados(a,b,c,TAM);
  multiplicar_arreglos(c, a, b, TAM);
  imprimir_resultados(a,b,c,TAM);
  imprimir_resultados(a,b,c,TAM);

  // Crear una función para imprimir el resultado de la misma forma que
  // está abajo
  return 0;
}