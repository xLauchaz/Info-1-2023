#include <stdio.h>
#include <stdlib.h>
struct personal
{
    int dni;
    char nombre[80];
    int legajo;
};
int main()
{
    struct personal *p;
    int n = 2;
    p = malloc (n*sizeof(struct personal));

    for (int i = 0; i < n; i++)
    {
        printf("Ingrese Nombre: ");
        scanf(" %80[^\n]s",(p+i)->nombre);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Nombre es: %s\n", (p+i)->nombre);
    }
    
    
    return 0;
}
