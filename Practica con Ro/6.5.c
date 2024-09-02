//Ejercicio 6.5
#include <stdio.h>
int ret_max(int a, int b)
{
  int max;
  if(a>b)
    max = a;
  else
    max = b;
  return max;
}
int main(void){
int num_1 , num_2 , num_3 , num_4 ;
printf (" Ingrese cuatro n´umeros diferentes : ");
scanf (" %d %d %d %d", &num_1 ,& num_2 ,& num_3 ,& num_4 );
printf("El numero %d es el máximo", ret_max(ret_max(num_1, num_2), ret_max(num_3, num_4)));  
return 0;
}
