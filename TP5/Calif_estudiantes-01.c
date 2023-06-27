#include <stdio.h>
//Rodriguez Lautaro 91167 1R1, TP5.
int main(void){
    //declaracion de variables a utilizar.
    int calif, cant_est,mayor = 0, menor = 100;
    float promedio = 0, total = 0;
    //validacion de la cantidad de estudiantes.
    do{
        printf("Ingrese la cantidad de estudiantes: ");
        scanf("%d", &cant_est);
        if (cant_est < 0 || cant_est > 100)
        {
            printf("Cantidad no valida, debe ser un numero positivo\n");
        }
    }while (cant_est < 0 || cant_est > 100);
    //ciclo para verificar las calificaciones.
    do{
        //ciclo para ingresar las calificaciones.
        for(int i = 0; i < cant_est; i++){
            printf("Ingrese la calificacion del estudiante %d: ", i+1);
            scanf("%d", &calif);
            total += calif;
            //registro de calif mas alta y mas baja.
            if (calif >= 0 && calif <= 100){
                if (calif < menor){
                    menor = calif;
                }
                if (calif > mayor){
                    mayor = calif;
                }
                promedio += calif;
            }
            else{
                printf("Calificacion no valida (0-100)\n");
                i--;
            }   
        }
    }while (calif < 0 || calif > 100);
    printf("El promedio de las calificaciones es: %.2f\n", promedio/cant_est);
    printf("La calificacion mas alta es: %d\n", mayor);
    printf("La calificacion mas baja es: %d\n", menor);
    return 0;
}
