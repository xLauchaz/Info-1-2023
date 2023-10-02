/*1. Declarar un arreglo de tamaño TAM para almacenar las calidades de las piezas.
2. Llamar a las funciones mencionadas anteriormente para cargar los datos, calcular la cantidad de piezas defectuosas 
y válidas, y mostrar los resultados en pantalla.
3. Imprimir la lista de todas las piezas ingresadas.
4. Imprimir la lista de piezas válidas ordenadas de menor a mayor calidad.
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 200
// Función para cargar la cantidad tam de elementos a utilizar
// la función devuelve un entero entre 0 y TAM
int ingresarValidarTam(void);

// Función para cargar los tam elementos en el arreglo
void cargarArreglo(float *arr,const int cantidad_piezas);

// Función para calcular la cantidad de piezas defectuosas
int calcularDefectuosas(const float *arr,const int cantidad_piezas);

// Función para calcular la cantidad de piezas válidas
int calcularValidas(const float *arr,const int cantidad_piezas);

// Función para mostrar todas las piezas ingresadas
void mostrarPiezas(const float *arr,const int cantidad_piezas);

// Función para mostrar las piezas válidas ordenadas
void mostrarPiezasValidasOrdenadasMenorMayor(const float *arr, int const cantidad_piezas);

int main(void) {

  float arreglo[TAM] = {0};
  int tam, defectuosas, validas;

  tam = ingresarValidarTam();
  cargarArreglo(arreglo, tam);
  defectuosas = calcularDefectuosas(arreglo, tam);
  validas = calcularValidas(arreglo, tam);
  printf("\nVálidas: %d\nDefectuosas: %d\n", validas, defectuosas);
  printf("\nArreglo desordenado:\n");
  mostrarPiezas(arreglo, tam);
  mostrarPiezasValidasOrdenadasMenorMayor(arreglo, tam);

  return 0;
}
int ingresarValidarTam(void)
{
  int tam;
  do
  {
    printf("Ingrese la cantidad de piezas a evaluar: ");
    scanf("%d", &tam);
  }while(tam < 1 || tam > TAM);
  return tam;
}
void cargarArreglo(float *arr, const int cantidad_piezas)
{
  double aux;
  for(int i = 0; i < cantidad_piezas; i++)
  {
    printf("Ingrese la calidad de la pieza: ");
    scanf("%lf", &aux);
    if(aux <= 0)
    {
      i--;
    }
    else
    {
      *(arr+i) = aux;
    }
  }
}
int calcularDefectuosas(const float *arr,const int cantidad_piezas)
{
  int defectuosas = 0;
  for(int i = 0; i < cantidad_piezas; i++)
  {
    if(*(arr+i) < 20 || *(arr+i) > 200)
    {
      defectuosas++;
    }
  }
  return defectuosas;
}
int calcularValidas(const float *arr,const int cantidad_piezas)
{
  int validas = 0;
  for(int i = 0; i < cantidad_piezas; i++)
  {
    if(*(arr+i) >= 20 && *(arr+i) <= 200)
    {
      validas++;
    }
  }
  return validas;
}
void mostrarPiezas(const float *arr,const int cantidad_piezas)
{
  for(int i = 0; i < cantidad_piezas; i++)
  {
    if (*(arr+i) >= 20 && *(arr+i) <= 200)
    {
      printf("%.2f\n", *(arr+i));
    }
    
  }
}
void mostrarPiezasValidasOrdenadasMenorMayor(const float *arr, int const cantidad_piezas)
{
  float aux[cantidad_piezas];    
  for(int i = 0; i < cantidad_piezas; i++)
  {
    if(*(arr+i) >= 20 && *(arr+i) <= 200)
    {
      aux[i] = *(arr+i);
    }
  }
  for(int i = 0; i < cantidad_piezas; i++)
  {
    for(int j = 0; j < cantidad_piezas-1; j++)
    {
      if(aux[j] > aux[j+1])
      {
        float aux2 = aux[j];
        aux[j] = aux[j+1];
        aux[j+1] = aux2;
      }
    }
  }
  printf("\nArreglo ordenado:\n");
  mostrarPiezas(aux, cantidad_piezas);
}