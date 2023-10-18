#include <stdio.h>

typedef struct 
{
    char nombre[20];
    int cantidad;
    float precio;
}producto_t;

int main(void)
{
    producto_t producto;
    producto_t *p;

    p = &producto;

    printf("Ingrese el nombre: ");
    scanf("%s",producto.nombre);
    printf("Ingrese la cantidad disponible: ");
    scanf("%d",&producto.cantidad);
    printf("Ingrese el precio: ");
    scanf("%d",&producto.precio);

    /*equivalencias de punteros
        p->nombre
        producto.nombre
        (*p).nombre
    */
   printf("Hay [%d] unidades del producto [%s] con el precio de [%d]\n", p->cantidad,producto.nombre,(*p).precio);
}
