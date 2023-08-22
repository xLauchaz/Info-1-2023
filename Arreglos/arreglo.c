#include <stdio.h>

int main(void){
/*en c los arreglos simepre empiezan en cero*/
    int notas[5] = {10, 9, 8, 7, 6};
    int nota = 10;

    printf("La nota es: %d\n", nota);
    printf("LA nota indice 3 es: %d\n", notas[3]);

    return 0;
}