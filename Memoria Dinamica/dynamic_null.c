#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *pvar;
     pvar = malloc(80);

     if (pvar == NULL)
     {
         printf("Es Null\n");
     }
     else
     {
        printf("Pedi memoria\n");
     }
     
    return 0;
}