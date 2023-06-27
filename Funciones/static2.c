#include <stdio.h>

int main(void){

    static int i = 0;
    printf("i: %d\n", i++);
    main();
    //numero de stack overflow, es el maximo que tiene para realizar este programa que es : 523688

    return 0;
}