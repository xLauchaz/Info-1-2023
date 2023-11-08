#include <stdio.h>

int main()
{
    char *nombres[5] = {"Lautaro","Eduardo","Santiago","Lourdes","Pablo"};
    for (int i = 0; i < 5; i++)
    {
        char *p = nombres[i];
    
        nombres[i] = nombres[i+1];
        nombres[i+i] = p;
    }
    
    for (int i = 0; i < 5; i++)
    {
        printf("%s\n",nombres[i]);
    }
    
    return 0;
}