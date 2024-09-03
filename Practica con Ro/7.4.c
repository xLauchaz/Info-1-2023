//ejercicio 7.4
#include <stdio.h>
#define N 5
//Comienzo de la función principal
int main(){
  //declaración de variables
  int i;
  int a[N];
  //Recorro el arreglo
  for(i = 0; i<N;i++){
    printf("Ingrese el elemento a[%d]: ",i);
    scanf("%d",&a[i]);
    if (a[i]<0||a[i]>100)
    {
    do
    {
      printf("Ingrese el elemento a[%d]:",i);
      scanf("%d",&a[i]);
    } while (a[i]<0||a[i]>100);
    }
  }
  for (i = 0; i < N; i++)
  {
    printf("%d\n",a[i]);
  }
  
  return 0;
}