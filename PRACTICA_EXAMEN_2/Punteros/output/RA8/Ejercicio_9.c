#include <stdio.h>
#define N 10
void swap(int *a, int*b);
void validar_positividad(int *a);
void validar_no_primo(int *a);

int main(void)
{
  int arreglo[N];
  validar_positividad(arreglo);
  return 0;
}
void validar_positividad(int *a)
{
  for (int i = 0; i < N; i++)
  {
    do
    {
      printf("Ingrese un numero entre 0 y 100 al arreglo[%d]: ",i);
      scanf("%d",(a+i));
    } while (*(a+i)<0 || *(a+i)>100);
    
  }
  
}
void validar_no_primo(int *a)
{

}
void swap(int *a, int*b)
{

}