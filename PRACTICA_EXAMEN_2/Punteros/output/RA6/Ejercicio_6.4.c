#include <stdio.h>

int ret_max(int a, int b)
{
  int max;
  if (a > b)
  {
    max = a;
  }
  else
  {
    max = b;
  }
  return max;
}

int main(void)
{
  int num_1;
  int num_2;
  int max;
  printf("Ingrese dos numeros diferentes: ");
  scanf("%d %d", &num_1,&num_2);
  max=ret_max(num_1,num_2);
  printf("El numero %d es el maximo", max);
  return 0;
}