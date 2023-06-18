#include <stdio.h>
int main(int argc, char const *argv[])
{
    int op;
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. salir");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        printf("Ingresó Suma\n");
        break;
    case 2:
        printf("Ingresó Resta\n");
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
