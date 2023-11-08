#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int *p;
    printf("Ingrese los elementos que necesite: ");
    scanf("%d", &n);
    p = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        *(p+i) = i*i;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%p = %d\n",p+i, *(p+i));

    }
    free(p);
    
    return 0;
}