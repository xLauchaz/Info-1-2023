#include <stdio.h>

int main(void){
    int notas, A = 0,D = 0,P = 0;

    do
    {
        printf("Digite uma nota: ");
        scanf("%d", &notas);
        if(notas >= 0 && notas <= 10){
            if(notas >= 8){
                P++;
            }else if(notas >= 6){
                A++;
            }else{
                D++;
            }
        }
    } while (notas != -1);
        printf("Cantidad de Aprobados: %d\n", A);
        printf("Cantidad de Desaprobados: %d\n", D);
        printf("Cantidad de Promocionados: %d\n", P);
    return 0;
    }
