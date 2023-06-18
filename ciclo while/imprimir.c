#include <stdio.h>

int main(void)
{
    int operacion;
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. salir\n");
    printf("Ingrese una opción: ");
    scanf("%d", &operacion);

    while (operacion >3 || operacion < 1)
    {
        printf("Opción no válida\n");
        printf("Ingrese una opción: ");
        scanf("%d", &operacion);   
    }
    
    return 0;
}
