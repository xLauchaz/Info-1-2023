#include <stdio.h>
#include <unistd.h>
#define TAM 100
int main()
{
    int i = 0;
    while (i <= TAM)
    {
        printf("i = %d\n", i);
        sleep(1);
        i++;
    }
}