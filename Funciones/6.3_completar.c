#include <stdio.h>
void imprime_mayor(int x, int y){
    if (x > y){
        printf("El mayor es %d\n", x);
    } 
    else {
        printf("El mayor es %d\n", y);
    }
}
int main(void){

    int num_1;
    int num_2;
    printf("Ingrese dos números diferentes: ");
    scanf("%d %d", &num_1, &num_2);

    imprime_mayor(num_1, num_2);

    return 0;
}