#include <stdio.h>
void imprimeCaracteres(const char *ptrS);

int main()
{
    char cadena[] = "Hola me llamo Lautaro";
    printf("La cadena es:\n");
    imprimeCaracteres(cadena);
    printf("\n");
    return 0;
}
void imprimeCaracteres(const char *ptrS)
{
    for (;*ptrS != '\0'; ++ptrS)
    {
        printf("%c", *ptrS);
    }
    
}
