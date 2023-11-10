#include <stdio.h>

struct dato{
    int a;
    char b;
};

int main()
{
    struct dato d = {1, 'a'};

    printf("a = %d\n", d.a);
    printf("b = %c\n", d.b);

    return 0;
}