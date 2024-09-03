//Ejercicio 6.7 guia

#include <stdio.h>
void num_primos(int x);
int main(void)
{
  int i, num;
  printf("Ingrese un numero: ");
  scanf("%d", &num);
  printf("Los números primos menores que %d son: \n",num);
  for(i=0;i<num;i++)
  {
    num_primos(i);
  }
  return 0;
}
void num_primos(int x)
{
  if((x%2)!=0)
    printf("%d\n",x);
}
