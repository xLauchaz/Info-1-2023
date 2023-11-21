#include <stdio.h>
void imprimir_cadena(const char*);
int main(int argc, char const *argv[])
{
    char nombre[] = "Hola me llamo Lautaro";
    imprimir_cadena(nombre);
    return 0;
}
void imprimir_cadena(const char *ptrS)
{
    for (; *ptrS != '\0'; ptrS++)
    {
        printf("%c", *ptrS);
    }
    puts("");
    
}