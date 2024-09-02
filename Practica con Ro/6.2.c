//Ejercicio 6.2 guia

#include <stdio.h>
float ingreso_numero(void){
  float num;
  printf("Ingrese un número: ");
  scanf("%f",&num);
  return num;
}

int main(void){
  	printf("Usted ingreso el número %f\n", ingreso_numero());
  return 0;
}
