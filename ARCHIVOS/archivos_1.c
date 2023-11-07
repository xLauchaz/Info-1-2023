#include <stdio.h>

int main()
{
    FILE *Fptr;

    char nombre[15];
    char apellido[15];
    int num;
    if ((Fptr = fopen("nombres.txt", "r")) == NULL)
    {
        puts("Error al abrir el archivo");
    }
    else
    {
        printf("Archivo abierto\n");
        while (!feof(Fptr))
        {
            fscanf(Fptr, "%s %s %d", nombre, apellido, &num);
            printf("%s %s %d\n", nombre, apellido, num);
        }
        fclose(Fptr);
    
    }
    
    return 0;
}