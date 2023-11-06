#include <stdio.h>

int main()
{
    char *nombres[5] = {"Lautaro","Eduardo","Santiago","Lourdes","Pablo"};
    char *p = nombres[0];
    for (int i = 0; i < 5; i++)
    {
        nombres[i] = nombres[i+1];
        nombres[i+1] = p;
        printf("%s\n",nombres[i]);
    }
    return 0;
}