//Ejercicio 6.1 guia
#include <stdio.h>

void intro(void)
{
printf("Bienvenidos! Comenzamos en ");
}
int main(void){
  int i;
  
  printf("%s",intro);
  
  for( i=10;i>0;i--){
 	 			intro();
    		printf("%d...\n",i);
	}
  
  return 0;
}