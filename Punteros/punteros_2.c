#include <stdio.h>

int main(void){
    float nota;
    float *pnota;
    nota = 9;
    pnota = &nota;

    printf("pnota es: %f\n", *pnota);
    printf("Dir de nota es: %f\n", nota);

    return 0;
}