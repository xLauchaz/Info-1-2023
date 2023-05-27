#include <stdio.h>
int main(void)
{
   int num1;
   int num2;
   int suma;

   printf("Ingrese el primer número: ");
   scanf("%d", &num1);
   printf("Ingrese el segundo número: ");
   scanf("%d", &num2);

   suma = num1 + num2;
   printf("su resultado es:%d\n", suma);
    return 0;
}