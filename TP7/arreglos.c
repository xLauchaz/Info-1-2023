/*Escribir un programa en enguaje C que permita a un almacen gestionar una lista de precios y su codigo de barra.
    El programa debe utilizar una cantidad TAM de códigos de barra, otro para el precio y debe ofrecer las siguientes funcionalidades
    a. Solicitar al usuario ingresar una cantidad TAM de códigos de barra con su precio, y agregarlo 
    a la lista de productos. TAM es una constante definida al inicio del código.

    b. Los precios de los productos son número decimales y no pueden ser negativos.

    c. Los códigos de barra son positivos enteros.

    d. Al finalizar la carga de los producots, mostrar todos los números. El programa debe mostrar en pantalla 
    la lista completa de productos almacenados.

    e. Buscar e imprimir el producto más caro. El programa debe encontrar y mostrar en pantalla el mayor precio en la lista e imprimir
     su código de barra.

    f. Buscar e imprimir el producto más barato. El programa debe encontrar y mostrar en pantalla el menor precio en la lista e 
    imprimir su código de barra.

    g. Imprimir 3 productos más caros: El programa deber imprimir los 3 productos más caros en orden

    h. Imprimir 3 productos más baratos: El programa deber imprimir los 3 productos más baratos en orden*/
#include <stdio.h>
#define TAM 5

int main(void){
    int codigos[TAM];
    float precios[TAM];
    int i, j, auxCodigo;
    float auxPrecio;
    //ingreso de datos
    for(i = 0; i < TAM; i++){
        printf("Ingrese el codigo de barra del producto %d: ", i+1);
        scanf("%d", &codigos[i]);
        printf("Ingrese el precio del producto %d: ", i+1);
        scanf("%f", &precios[i]);
    }
    //ordenamiento de datos
    for(i = 0; i < TAM-1; i++){
        for(j = i+1; j < TAM; j++){
            if(precios[i] < precios[j]){
                auxPrecio = precios[i];
                precios[i] = precios[j];
                precios[j] = auxPrecio;

                auxCodigo = codigos[i];
                codigos[i] = codigos[j];
                codigos[j] = auxCodigo;
            }
        }
    }
    //impresion de datos
    printf("\n\nLista de productos:\n");
    for(i = 0; i < TAM; i++){
        printf("Codigo: %d\tPrecio: %.2f\n", codigos[i], precios[i]);
    }
    //impresion del mas caro
    printf("\n\nProducto mas caro:\n");
    printf("Codigo: %d\tPrecio: %.2f\n", codigos[0], precios[0]);
    //impresion del mas barato
    printf("\n\nProducto mas barato:\n");
    printf("Codigo: %d\tPrecio: %.2f\n", codigos[TAM-1], precios[TAM-1]);
    //impresion de los 3 mas caros
    printf("\n\n3 productos mas caros:\n");
    for(i = 0; i < 3; i++){
        printf("Codigo: %d\tPrecio: %.2f\n", codigos[i], precios[i]);
    }
    //impresion de los 3 mas baratos
    printf("\n\n3 productos mas baratos:\n");
    for(i = TAM-1; i > TAM-4; i--){
        printf("Codigo: %d\tPrecio: %.2f\n", codigos[i], precios[i]);
    }
    return 0;
}