//Ejercicio 7.3
#include <stdio.h>
#define N 5
//Comienzo de la función principal
int main(){
  //declaración de variables
  int i;
  int a[N];
  int b[N];
  //Recorro el arreglo
  for(i=0;i<N;i++){
  printf("Ingrese un número %d:", i);
  scanf("%d", &a[i]);
  }
  //copio el arreglo acumulando el valor del primer arreglo, por ejemplo b[o]será a[o], b[1] será a[0]+a[1], b[2] será a[0]+a[1]+a[2] y así sucesivamente
  for(i=0;i<N;i++){
    if(i==0){
      b[i]=a[i];
    }else{
      b[i]=b[i-1]+a[i];
    }
  }
  //Imprimo el arreglo b
  for(i=0;i<N;i++){
    printf("El valor acumulado de los elementos del arreglo a hasta la posición %d es: %d\n", i, b[i]);
  }
  
  return 0;
}