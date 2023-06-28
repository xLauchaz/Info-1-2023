#include <stdio.h>

long int producto(int a, int b){
    if(b==1){
        return a;
    }
    else{
        return a + producto(a,--b);
    }
}

int main(void){

    int a, b;
    long int res;
    printf("Ingrese la base: ");
    scanf("%d", &a);
    printf("Ingrese el exponente: ");
    scanf("%d", &b);
    res = producto(a, b);
    printf("El resultado es: %u\n", res);
    return 0;
}