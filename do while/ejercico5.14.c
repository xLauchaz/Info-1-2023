#include <stdio.h>
int main(void){
    /*escribir un algoritmo que determine el mayor de N numeros positivos ingresados . 
    El usuario debe ingresar cada uno de los N números. Para terminar
se debe ingresar un -1.*/

    int num = 0, mayor = 0;
    do
    {
       printf("Ingrese un numero: ");
       scanf("%d",&num);
         if (num > mayor)
         {
              mayor = num;
         }
    } while (num != -1 );
    printf("El mayor es: %d\n",mayor);

    
    return 0;
}