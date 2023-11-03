#include <stdio.h>
#include <ctype.h>

void convierteAMayusculas(char *ptrS);

int main()
{
    char cadena[] = "Hola a todods me llamo Lautaro";

    printf("Ka cadena antes de la conversion es: %s\n", cadena);
    convierteAMayusculas(cadena);
    printf("La cadena despues de la conversion : %s\n", cadena);

    return 0;
}
 void convierteAMayusculas(char *ptsS)
 {
    while (*ptsS != '\0')
    {
        if (islower(*ptsS))
        {
            *ptsS = toupper(*ptsS);
        }
        ++ptsS;
    }
    
 }