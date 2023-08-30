#include <stdio.h>
int ingreso(void);
int seleccion(int);
int suma(void);
int resta(void);
int mult(void);
float div(void);
void result(float,int);
int main(void){
    int op;
    float resp;
    op = ingreso();
    resp = seleccion(op);
    result(resp, op);
    return 0;
}
int ingreso(void){
    int op;
    printf("1- Suma\n2- Resta\n3- Multiplicacion\n4- Division\n");
    do
    {
        printf("Ingrese un opcion a realizar: ");
        scanf("%d", &op);
        if(op < 1 || op > 4){
            printf("La opcion es incorrecta\n");
        }
    } while (op < 1 || op > 4);
    return op;
}
int seleccion(int a){
    float b;
    switch (a)
    {
    case 1:
        b = suma();
        break;
    case 2:
        b = resta();
        break;
    case 3:
        b = mult();
        break;
    case 4:
        b = div();
        break;
    default:
        break;
    }
    return b;
}
int suma(void){
    int total = 0, num = 0;
    printf("Ingrese los numeros a sumar, -1 para terminar: ");
    while(num != -1)
    {
        scanf("%d",&num);
        if(num != -1){
        total += num;
        }
    }
    return total;
}
int resta(void){
    int total = 0, num = 0, cont = 0;
    printf("Ingrese los numeros a restar, -1 para terminar: ");
    while (num != -1)
    {
        scanf("%d",&num);
        if(num != -1){
            if(cont == 0){
                total = num;
            }else{
                total -= num;
            }
            cont++;
        }
    }
    return total;
}
int mult(void){
    int total = 1, num = 0;
    printf("Ingrese los numeros a multiplicar, -1 para terminar: ");
    while(num != -1)
    {
        scanf("%d",&num);
        if(num != -1){
        total *= num;
        }
    }
    return total;
}
float div(void){
    int total = 0, num = 0, cont = 0;
    printf("Ingrese los numeros a dividir, -1 para terminar: ");
    while (num != -1)
    {
        scanf("%d",&num);
        if(num != -1){
            if(cont == 0){
                total = num;
            }else{
                total /= num;
            }
            cont++;
        }
    }
    return total;
}
void result(float x,int y){
    switch (y)
    {
    case 1:
        printf("El resultado de la Suma es: %.f\n", x);
        break;
    case 2:
        printf("El resultado de la Resta es: %.f\n", x);
        break;
    case 3:
        printf("El resultado de la Multiplicacion es: %.f\n", x);
        break;
    case 4:
        printf("El resultado de la Division es: %.2f\n", x);
        break;
    default:
        break;
    }
}