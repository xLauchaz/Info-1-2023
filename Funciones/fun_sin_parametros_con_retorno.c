#include <stdio.h>
//Definir funcion
int ingresar_legajo(void){
    int legajo;
    printf("Ingrese su legajo: ");
    scanf("%d", &legajo);
    return legajo;
}
int main(void){
    int legajo;

    legajo = ingresar_legajo();
    printf("Su legajo es: %d\n", legajo);

    return 0;
}