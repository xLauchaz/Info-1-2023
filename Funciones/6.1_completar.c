#include <stdio.h>

void intro(void){
    printf("Bienvenidos! Comenzando en ");
}

int main(void){

    for (int i = 10; i > 0; i--)
    {
        intro();
        printf("%d...\n", i);
    }
    
    return 0;
}