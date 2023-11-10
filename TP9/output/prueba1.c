#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct {
  char nombre[40];
  int anio_nacimiento;
}autor_t;

typedef struct libro{
  char nombre[40];
  int cant_paginas;
  int cant_capitulos;
  int* paginas_por_capitulo;
  float precio;
  autor_t datos_autor;
}libro_t;

void ingresar_cantidad(int*);
void cargar_biblioteca(libro_t* bib, int cant);
void imprimir_biblioteca(libro_t* bib, int cant);
void ordenar_por_precio_menor_mayor(libro_t* bib, int cant);

int main(void) {

  libro_t biblioteca[TAM];
  int cantidad;

  ingresar_cantidad(&cantidad);

  cargar_biblioteca(biblioteca, cantidad);

  printf("===============================================\n");
  printf("Imprimr biblioteca desordenada: \n");
  imprimir_biblioteca(biblioteca, cantidad);

  printf("===============================================\n");
  printf("Imprimir biblioteca ordenada: \n");
  ordenar_por_precio_menor_mayor(biblioteca, cantidad);
  imprimir_biblioteca(biblioteca, cantidad);
  for (int i = 0; i < cantidad; i++)
  {
    free(biblioteca[i].paginas_por_capitulo);
  }
  
  return 0;
}
void ingresar_cantidad(int * a)
{
  do {
        printf("Ingrese la cantidad de libros a cargar: ");
        scanf("%d", a);

        if (*a < 1 || *a > 10) {
            printf("Error: El valor debe estar entre 1 y 10. Inténtelo de nuevo.\n");
        }
    } while (*a < 1 || *a > 10);
}
void cargar_biblioteca(libro_t * bib, int cant)
{
  for (int i = 0; i < cant; i++)
  {
    printf("Ingrese el nombre del libro: ");
    scanf(" %[^\n]s", bib->nombre);
    printf("Ingrese la cantidad de capitulos: ");
    scanf("%d", &bib->cant_capitulos);
    bib[i].paginas_por_capitulo = calloc(bib->cant_capitulos, sizeof(int));
    for (int j = 0; j < bib->cant_capitulos; j++)
    {
      printf("Ingrese la cantidad de paginas del capitulo %d:", j+1);
      scanf("%d", &bib->paginas_por_capitulo[j]);
    }
    printf("Ingrese el precio del libro: ");
    scanf("%f", &bib->precio);
    printf("Ingrese el nombre del autor: ");
    scanf(" %[^\n]s", bib->datos_autor.nombre);
    printf("Ingrese el año de nacimiento del autor: ");
    scanf("%d", &bib->datos_autor.anio_nacimiento);
  }
}
void imprimir_biblioteca(libro_t *bib, int cant)
{
  bib->cant_paginas = 0;
  for (int i = 0; i < cant; i++)
  {
    printf("Nombre del libro: %s\n", bib->nombre);
    for (int j = 0; j < bib->cant_capitulos; j++)
    {
      bib[i].cant_paginas += bib[i].paginas_por_capitulo[j];
    }
    printf("Cantidad de paginas: %d\n", bib->cant_paginas);
    printf("Cantidad de capitulos: %d\n", bib->cant_capitulos);
    for (int j = 0; j < bib->cant_capitulos; j++)
    {
      printf("Cantidad de paginas del capitulo %d: %d\n", j+1, bib->paginas_por_capitulo[j]); 
    }
    printf("Precio del libro: %.2f\n", bib->precio);
    printf("Nombre del autor: %s\n", bib->datos_autor.nombre);
    printf("Fecha de nacimiento del autor: %d\n", bib->datos_autor.anio_nacimiento);
  }
  
}
void ordenar_por_precio_menor_mayor(libro_t * bib,int cant)
{
  libro_t temp;
  for (int i = 0; i < cant; i++)
  {
    for(int j = 0; j < cant-1-i; j++)
    {
      if(bib[j].precio < bib[j+1].precio)
      {
        temp = bib[j];
        bib[j] = bib[j+1];
        bib[j+1] = temp;
      }
    }
  }
  
}