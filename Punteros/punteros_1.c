#include <stdio.h>

int main(void){
    int nota;
    int *pnota;
    nota = 9;
    pnota = &nota;

    printf("pnota es: %p\n", pnota);
    printf("Dir de nota es: %p\n", &nota);

    return 0;
}