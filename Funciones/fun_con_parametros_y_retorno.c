#include <stdio.h>

int ingresar_legajo(void){
    int legajo;
    int dni;
    printf("Ingrese su legajo: ");
    scanf("%d", &legajo);
    printf("Ingrese su DNI: ");
    scanf("%d", &dni);
    //las funciones pueden devolver una sola variable al retorno.
    return legajo;
}
int main(void){

    int legajo;

    legajo = ingresar_legajo();
    printf("Su legajo es: %d\n", legajo);

    return 0;
}

/*Ejemplo complejo
    //definicion de la funcion
    float sumar(float n1, float n2){
        return n1 + n2;
    }
    
    #include <stdio.h>
    
    int main(void){
        float num1, num2, sum;
        sum = sumar(num1,num2); lo que esta entre parentesis son argumentos.
        printf("La suma es: %f\n", sum);
        return 0;
    }*/