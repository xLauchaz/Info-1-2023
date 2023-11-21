#include <stdio.h>

int pasar_por_valor(int n);
void pasar_por_referencia(int *ptrN);

int main()
{
    int n = 5;
    int p = 5;
    //pasamos el numero por valor
    n = pasar_por_valor(n);
    printf("El paso por valor nos devuelve que 5*5*5 = %d\n", n);
    //pasamos por referencia
    pasar_por_referencia(&p);
    printf("El paso por referencia nos devuelve que 5*5*5 = %d\n",p);
    return 0;
}
int pasar_por_valor(int n)
{
    return n*n*n;
}
void pasar_por_referencia(int *ptrN)
{
    *ptrN = *ptrN * *ptrN * *ptrN;
}