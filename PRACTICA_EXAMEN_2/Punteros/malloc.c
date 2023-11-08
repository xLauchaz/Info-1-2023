#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p;
    int *q;
    
    p = malloc(sizeof(int));
    q = malloc(sizeof *q);

    printf("p: %p\n",p);
    printf("q: %p\n",q);

    free(p);
    free(q);
    return 0;
}