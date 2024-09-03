//Ejercicio 7.2
#include <stdio.h>
#define N 5
//Comienzo de la función principal
int main(){
  //declaración de variables
  int i;
  int a[N];
  int max=0;
  //Recorro el arreglo
  for(i=0;i<N;i++){
  printf("Ingrese un número %d:", i);
  scanf("%d", &a[i]);
  }
  //busco el mayor elemento
  for(i=0;i<N;i++){
	
    if(a[i]>max){
      max=a[i];
    }
  }
  printf("El mayor número del arreglo es: %d", max);
  return 0;
}