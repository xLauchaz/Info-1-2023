#include <stdio.h>

int potencia(int a, int b)
{
    int res = 1;
    for(int i = 0; i < b; i++)
    {
        res *= a;
    }
    return res;
}

int main(void)
{
    int base, exp;

    printf("Ingrese base y exponente: ");
    scanf("%d %d", &base, &exp);
    printf("El numero %d elevado a la %d es: %d\n", base, exp, potencia(base,exp));
    return 0;
}