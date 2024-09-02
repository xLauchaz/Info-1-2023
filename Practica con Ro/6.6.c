#include <stdio.h>
int potencia(int base, int exp){
    int i, resultado = 1;
    for(i = 0; i < exp; i++){
        resultado *= base;
    }
    return resultado;
}
int main(void){
    int base, exp;
    printf("Ingrese base y explonente: "); 
    scanf("%d %d", &base, &exp);
    printf("El número %d elevado a la %d es: %d\n", base, exp, potencia(base, exp));
    return 0;
}