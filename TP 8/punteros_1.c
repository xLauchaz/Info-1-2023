/*1. Declarar un arreglo de tamaño TAM para almacenar las calidades de las piezas.
2. Llamar a las funciones mencionadas anteriormente para cargar los datos, calcular la cantidad de piezas defectuosas 
y válidas, y mostrar los resultados en pantalla.
3. Imprimir la lista de todas las piezas ingresadas.
4. Imprimir la lista de piezas válidas ordenadas de menor a mayor calidad.
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 100
// Función para cargar la cantidad tam de elementos a utilizar
// la función devuelve un entero entre 0 y TAM
/*La función int ingresarValidarTam(void) debe permitir al usuario ingresar la cantidad de piezas a evaluar 
y validar que esté dentro del rango [1, TAM], donde TAM es una constante definida con un valor predeterminado. 
Esta función debe devolver la cantidad de*/
int ingresarValidarTam(void);

// Función para cargar los tam elementos en el arreglo
/*La función void cargarArreglo(float *arr, const int cantidad_piezas) debe permitir al usuario cargar las calidades 
de las piezas en un arreglo arr de tamaño cantidad_piezas. Las calidades se representan como valores en punto flotante.
Las calidade de las piezas es un número decimal positivo. Se debe validar el ingreso para solo admitir números positivos.*/
void cargarArreglo(float *arr,const int cantidad_piezas);

// Función para calcular la cantidad de piezas defectuosas
/*La función int calcularDefectuosas(const float *arr, const int cantidad_piezas) debe calcular y retornar la cantidad de piezas
defectuosas en el arreglo arr. Las piezas defectuosas se consideran aquellas con una calidad menor a 20 y mayor a 200.*/
int calcularDefectuosas(const float *arr,const int cantidad_piezas);

// Función para calcular la cantidad de piezas válidas
/* La función int calcularValidas(const float *arr, const int cantidad_piezas) debe calcular y retornar la cantidad de
piezas válidas en el arreglo arr. Las piezas válidas se consideran aquellas con una calidad entre 20 y 200.*/
int calcularValidas(const float *arr,const int cantidad_piezas);

// Función para mostrar todas las piezas ingresadas
/*La función void mostrarPiezas(const float *arr, const int cantidad_piezas) debe mostrar en pantalla la lista de piezas
ingresadas en el arreglo arr.*/
void mostrarPiezas(const float *arr,const int cantidad_piezas);

// Función para mostrar las piezas válidas ordenadas
/*La función void mostrarPiezasValidasOrdenadasMenorMayor(const float *arr, const int cantidad_piezas) debe mostrar en 
pantalla las piezas válidas ordenadas de menor a mayor calidad.*/
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
