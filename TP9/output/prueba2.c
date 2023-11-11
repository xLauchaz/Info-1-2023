#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10

typedef struct {
    char nombre[40];
    int anio_nacimiento;
} autor_t;

typedef struct libro {
    char nombre[40];
    int cant_paginas;
    int cant_capitulos;
    int* paginas_por_capitulo;
    float precio;
    autor_t datos_autor;
} libro_t;

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
    printf("Imprimir biblioteca desordenada: \n");
    imprimir_biblioteca(biblioteca, cantidad);

    printf("===============================================\n");
    printf("Imprimir biblioteca ordenada por precio: \n");
    ordenar_por_precio_menor_mayor(biblioteca, cantidad);
    imprimir_biblioteca(biblioteca, cantidad);

    for (int i = 0; i < cantidad; i++) {
        free(biblioteca[i].paginas_por_capitulo);
    }

    return 0;
}

void ingresar_cantidad(int *a) {
    do {
        printf("Ingrese la cantidad de libros a cargar: ");
        scanf("%d", a);

        if (*a < 1 || *a > TAM) {
            printf("Error: El valor debe estar entre 1 y %d. Inténtelo de nuevo.\n", TAM);
        }
    } while (*a < 1 || *a > TAM);
}

void cargar_biblioteca(libro_t *bib, int cant) {
    for (int i = 0; i < cant; i++) {
        printf("Ingrese el nombre del libro: ");
        scanf(" %[^\n]s", bib[i].nombre);
        do
        {
          printf("Ingrese la cantidad de capítulos: ");
          scanf("%d", &bib[i].cant_capitulos);
        } while (bib[i].cant_capitulos < 1);
        
        bib[i].paginas_por_capitulo = calloc(bib[i].cant_capitulos, sizeof(int));
        bib[i].cant_paginas = 0;
        for (int j = 0; j < bib[i].cant_capitulos; j++) {
            do
						{
							printf("Ingrese la cantidad de páginas del capítulo %d:", j + 1);
            	scanf("%d", &bib[i].paginas_por_capitulo[j]);
						} while (bib[i].paginas_por_capitulo < 1);
						
            bib[i].cant_paginas += bib[i].paginas_por_capitulo[j];
        }

       do
			 {
				 printf("Ingrese el precio del libro: ");
        scanf("%f", &bib[i].precio);
			 } while (bib[i].precio < 1);
			 
        printf("Ingrese el nombre del autor: ");
        scanf(" %[^\n]s", bib[i].datos_autor.nombre);

        do
				{
					printf("Ingrese el año de nacimiento del autor: ");
        	scanf("%d", &bib[i].datos_autor.anio_nacimiento);
				} while (bib[i].datos_autor.anio_nacimiento < 1);
				
    }
}

void imprimir_biblioteca(libro_t *bib, int cant) {
    for (int i = 0; i < cant; i++) {
        printf("Nombre del libro: %s\n", bib[i].nombre);
        printf("Cantidad de páginas: %d\n", bib[i].cant_paginas);
        printf("Cantidad de capítulos: %d\n", bib[i].cant_capitulos);
        for (int j = 0; j < bib[i].cant_capitulos; j++) {
            printf("Cantidad de páginas del capítulo %d: %d\n", j + 1, bib[i].paginas_por_capitulo[j]);
        }
        
        printf("Precio del libro: %.2f\n", bib[i].precio);
        printf("Nombre del autor: %s\n", bib[i].datos_autor.nombre);
        printf("Año de nacimiento del autor: %d\n", bib[i].datos_autor.anio_nacimiento);
        puts("");
    }
}

void ordenar_por_precio_menor_mayor(libro_t *bib, int cant) {
    int i, j;
    libro_t temp;

    for (i = 0; i < cant - 1; i++) {
        for (j = 0; j < cant - i - 1; j++) {
            if (bib[j].precio > bib[j + 1].precio) {
                temp = bib[j];
                bib[j] = bib[j + 1];
                bib[j + 1] = temp;
            }
        }
    }
}
