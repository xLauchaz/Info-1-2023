#include <stdio.h>

void imprimir_incrementado(void){
    static int contador = 0;
    printf("contador: %d\n", contador++);
}
int main(void){

    for(int i = 0; i < 10; i++){
        imprimir_incrementado();
    }
    return 0;
}