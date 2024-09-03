//Ejercicio 7.1 guia
#include <stdio.h>
#define N 10
//Comienzo de la función principal
int main(){
  //declaración de variables
  int i;
  int a[N];
  
  for(i=0;i<N;i++){
  printf("Ingrese un número %d:", i);
  scanf("%d", &a[i]);
  }
  for(i=0;i<N;i++){
    if(a[i]<0){
      a[i]*=-1;
    }
  }
  for(i=0;i<N;i++){
    printf("%d\n", a[i]);
  }
  
  return 0;
}