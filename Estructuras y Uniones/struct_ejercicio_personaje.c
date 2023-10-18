#include <stdio.h>
#include <time.h>
#include <stdlib.h>
typedef struct 
{
    char apodo[20];
    int rango;
    float vida;
    float escudo;
    float sales;
    struct 
    {
        char nombre[20];
        char apellido[20];
        int edad;
    }info_personal;
    
}personaje_t;
int main(void)
{
    srand(time(NULL));

    personaje_t personaje, *pPersonaje;
    pPersonaje = &personaje;
    //inicializar escudo y sales en 0
    personaje.escudo = 0;
    personaje.sales = 0;
    personaje.vida = 150;
    personaje.rango = rand()%100;
    printf("----------Cargar los elementos directamente----------\n");
    printf("Ingrese su apodo: ");
    scanf("%s", &personaje.apodo);
    printf("Ingrese su nombre: ");
    scanf("%s", &personaje.info_personal.nombre);
    printf("Ingrese su apellido: ");
    scanf("%s", &personaje.info_personal.apellido);
    printf("Ingrese su edad: ");
    scanf("%d", &personaje.info_personal.edad);
    printf("----------Datos del personaje----------\n");
    printf("Apodo: %s\n", personaje.apodo);
    printf("Rango: %d\n", personaje.rango);
    printf("Vida: %f\n", personaje.vida);
    printf("Escudo: %f\n", personaje.escudo);
    printf("Sales: %f\n", personaje.sales);
    printf("Nombre: %s\n",personaje.info_personal.nombre);
    printf("Apellido: %s\n", personaje.info_personal.apellido);
    printf("----------Cargar los elemnetos mediante puntero----------");
    printf("Ingrese su apodo: ");
    scanf("%s", &pPersonaje->apodo);
    printf("Ingrese su nombre: ");
    scanf("%s", &pPersonaje->info_personal.nombre);
    printf("Ingrese su apellido: ");
    scanf("%s", &pPersonaje->info_personal.apellido);
    printf("Ingrese su edad: ");
    scanf("%d", &pPersonaje->info_personal.edad);
    printf("----------Datos del personaje----------\n");
    printf("El apodo es: %s\n", pPersonaje->apodo);
    printf("Rango: %d\n", pPersonaje->rango);
    printf("Vida: %f\n", pPersonaje->vida);
    printf("Escudo: %f\n", pPersonaje->escudo);
    printf("Sales: %f\n", pPersonaje->sales);
    printf("Nombre: %s\n",pPersonaje->info_personal.nombre);
    printf("Apellido: %s\n", pPersonaje->info_personal.apellido);
    }
