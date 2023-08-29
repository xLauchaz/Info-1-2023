#include <stdio.h>
int ingreso(void);
int seleccion(int);
int suma(void);
int resta(void);
void result(int,int);
int main(void){
    int op,resp;
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
    int b;
    switch (a)
    {
    case 1:
        b = suma();
        break;
    case 2:
        b = resta();
        break;
    default:
        break;
    }
    return b;
}
int suma(void){
    int total = 0, num = 0;
    while(num != -1)
    {
        printf("Ingrese los numeros a sumar, -1 para terminar: ");
        scanf("%d",&num);
        if(num != -1){
        total += num;
        }
    }
    return total;
}
int resta(void){
    int total = 0, num = 0, cont = 0;
    while (num != -1)
    {
        printf("Ingrese los numeros a restar, -1 para terminar: ");
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
void result(int x,int y){
    switch (y)
    {
    case 1:
        printf("El resultado de la Suma es: %d\n", x);
        break;
    case 2:
        printf("El resultado de la Resta es: %d\n", x);
        break;
    default:
        break;
    }
}