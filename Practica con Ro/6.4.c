//Ejercicio 6.4
#include <stdio.h>
int ret_max(int a, int b)
{
  int max;
  if(a>b)
    max=a;
  else
    max=b;
  return max;
}
int main(void)
{
  int num_1;
  int num_2;
  
  printf("Ingrese dos números: ");
  scanf("%d %d",&num_1,&num_2);
  printf("El número %d es el maximo", ret_max(num_1, num_2));
  return 0;
}
