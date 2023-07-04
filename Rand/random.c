#include <stdio.h>
#include <stdlib.h>

int main(void){
    /*srand(10); //semilla fija  */
    srand(time(NULL)); //semilla aleatoria
    printf("tiempo: %ld\n", time(NULL));
    printf("Numero: %d\n\n", rand());
    return 0;
}