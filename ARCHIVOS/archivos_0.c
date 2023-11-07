#include <stdio.h>
//gcc archivos_0.c -o archivos_0
int main()
{
    FILE *Fptr;
    char caracter;

    Fptr = fopen("nombres.txt", "r");
    if(Fptr == NULL)
    {
        puts("Error al abrir el archivo");
    }
    else
    {
        printf("Archivo abierto\n");
        while (!feof(Fptr))
        {
            caracter = fgetc(Fptr);
            printf("%c", caracter);
        }
        fclose(Fptr);
    }
    return 0;
}