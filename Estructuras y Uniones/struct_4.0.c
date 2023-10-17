#include <stdio.h>
struct location
{
    char calle[30];
    int altura;
};
struct persona
{
    char nombre[30];
    int edad;
    struct location loc;
};
struct perrro
{
    char nombre[20];
    float altura;
    struct 
};

int main(void)
{
    struct perrro bobi1 = {20,"Luke"};
    struct perrro bobi2 = {20,"brownie"};
    struct persona p1 = {"Juan", 20, {"Av. Siempre Viva", 123}};
    struct persona p2 = {"Pedro", 30, {"Av. Siempre Viva", 123}};
    printf("El nombre de la persona es: %s\n", p1.nombre);
    printf("La edad de la persona es: %d\n", p1.edad);
    printf("La calle de la persona es: %s\n", p1.loc.calle);
    printf("La altura de la persona es: %d\n", p1.loc.altura);
    printf("El nombre de la persona es: %s\n", p2.nombre);
    printf("La edad de la persona es: %d\n", p2.edad);
    printf("La calle de la persona es: %s\n", p2.loc.calle);
    printf("La altura de la persona es: %d\n", p2.loc.altura);
    return 0;
    
}
