//ejeercicio arreglo de estructuras
#include <stdio.h>
#define TAM 2


typedef struct {
  char nombre[20];
  int cantidad;
  float precio;
}producto_t;

/* Completar la función para cargar los datos mediante un puntero*/
void cargar_estructura(producto_t*);

void imprimir_estructura(producto_t);

int main(void)
{
  producto_t productos[TAM];

  for (int i = 0; i < TAM; i++){
    cargar_estructura(&productos[i]);
  }

  for (int i = 0; i < TAM; i++)
    imprimir_estructura(productos[i]);

  return 0;
}
void cargar_estructura(producto_t* prod)
{
    printf("Ingrese el nombre: ");
    scanf("%s",prod->nombre);
    printf("Ingrese la cantidad: ");
    scanf("%d",&prod->cantidad);
    printf("Ingrese el precio: ");
    scanf("%f",&prod->precio);
}
void imprimir_estructura(producto_t variable){
  printf("Hay [%d] unidades del producto [%s] con un valor de %f\n",
                                                                    variable.cantidad,
                                                                    variable.nombre,
                                                                    variable.precio);
}