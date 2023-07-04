#include <stdio.h>
/*Funcion que devuleve un numero ingresado por el usuario dentro del rango especificado*/
int ingresar_y_validar(int inferior, int superior);
int main(void){
    int num = ingresar_y_validar(10,100);
    printf("El numero ingresado es: %d\n", num);

    return 0;
}
int ingresar_y_validar(int inferior, int superior){
    int num;
    do
    {
        printf("Ingrese un numero entre %d y %d: ", inferior, superior);
        scanf("%d", &num);
        if (num < inferior || num > superior)
        {
            printf("El numero ingresado no esta dentro del rango especificado\n");
        }
        
    } while (num < inferior || num > superior);
    return num;
}
