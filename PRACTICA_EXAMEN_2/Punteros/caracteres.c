#include <stdio.h>

int main()
{
    char *nombres[5] = {"Lautaro","Eduardo","Santiago"," "," "};

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n",nombres[i]);
    }
    
    return 0;
}