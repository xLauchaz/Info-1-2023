#include <stdio.h>
//Inicializar elemento a elemento

int main(void){
    char nombre[] = "Lautaro Rodriguez";
    //nombre[7] = 0; esto hace que se ponga un /0 en ese lugar del arreglo en la memoria, causando un final de cadena.
    printf("Hola %s!\n", nombre);
    printf("%ld\n", sizeof(nombre));

    return 0;
}