//LANZAR UN DADO 6000 VECES
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 7
//COMIENZO DE LA EJECUCION DEL PROGRAMA
int main(void){
    //DECLARACION DE VARIABLES
    int cara;
    int tiro;
    int frecuencia[TAM]={0};
    //SE GENERA LA SEMILLA DE NUMEROS ALEATORIOS
    srand(time(NULL));
    //SE TIRA EL DADO 6000 VECES
    for(tiro = 1; tiro <=6000;tiro++){
        cara = 1 +rand() % 6;
        ++frecuencia[cara];
    }
    printf("%s%17s\n", "Cara", "Frecuencia");

    for(cara = 1; cara < TAM; cara++){
        printf("%4d%17d\n", cara,frecuencia[cara]);
    }

    return 0;
}