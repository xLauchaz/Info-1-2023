#include <stdio.h>

int main(void){
    int calif;
    printf("Ingrese la calificacion: ");
    scanf("%d", &calif);

    if(calif >= 90){
        printf("Calificacion: A\n");

    }
    else if(calif >= 80 && calif <= 90){
        printf("Calificacion: B\n");
        
    }
    else if (calif >= 70 && calif <= 80){
        printf("Calificacion: C\n");
        
    }
    else if (calif >= 60 && calif <= 70){
        printf("Calificacion: D\n");
        
    }
    else{
        printf("Calificacion: F\n");
    }
    
    return 0;
}