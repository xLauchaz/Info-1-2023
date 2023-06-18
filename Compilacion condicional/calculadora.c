#include <stdio.h>
#define OPERACIONES

int main(void){
    int operacion = 0;
    float num1,num2;
    do
    {
        printf("1. Suma\n2. Resta\n");
        #ifdef OPERACIONES
        do
        {
            printf("3. Multiplicacion\n");
            printf("4. Division\n");
        } while (operacion < 0 && operacion >= 2);
        #endif
        printf("Ingrese la operacion que desea realizar: ");
        scanf("%d",&operacion);
    } while (operacion < 0 && operacion >= 4);
    
    
        switch (operacion)
        {
        case 1: // Suma
            printf("Ingrese el primer numero: ");
            scanf("%f",&num1);
            printf("Ingrese el segundo numero: ");
            scanf("%f",&num2);
            printf("El resultado de la suma es: %.2f\n",num1+num2);
            break;
        case 2: // Resta
            printf("Ingrese el primer numero: ");
            scanf("%f",&num1);
            printf("Ingrese el segundo numero: ");
            scanf("%f",&num2);
            printf("El resultado de la resta es: %.2f\n",num1-num2);
            break;
        case 3: // Multiplicacion
            #ifdef OPERACIONES
                printf("Ingrese el primer numero: ");
                scanf("%f",&num1);
                printf("Ingrese el segundo numero: ");
                scanf("%f",&num2);
                printf("El resultado de la multiplicacion es: %.2f\n",num1*num2);
            #endif
            break;
        case 4: // Division
            #ifdef OPERACIONES
                printf("Ingrese el primer numero: ");
                scanf("%f",&num1);
                printf("Ingrese el segundo numero: ");
                scanf("%f",&num2);
                printf("El resultado de la division es: %.2f\n",num1/num2);
            #endif
        default:
            printf("Opcion no valida\n");
            break;
        }
    return 0;
}