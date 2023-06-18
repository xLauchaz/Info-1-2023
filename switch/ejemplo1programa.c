#include<stdio.h>

int main(void){

    int op;
    float a, b;
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. salir\n");
    printf("Ingrese una opción: ");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        printf("Ingrese 2 numeros:");
        scanf("%d %d", &a, &b);
        printf("La suma es: %f\n", a+b);
        break;
    case 2:
        printf("Ingrese 2 numeros:\n");
        scanf("%d %d", &a, &b);
        printf("La resta es: %f\n", a-b);
        break;
    case 3:
        printf("Adios\n");
        break;
    default:
        printf("Opción no válida\n");
        break;
    }  
    return 0;
}
