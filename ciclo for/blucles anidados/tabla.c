#include <stdio.h>
//modificar el programa para que imprima una tabla como la siguiente
/*0
  10 11
  20 21 22
  30 31 32 33
  40 41 42 43 44
  */
int main(void){

    int i,j,fil,col;
    do{
    printf("Ingrese el numero de filas: ");
    scanf("%d",&fil);
    }while(fil<= 0);
    do{   
    printf("Ingrese el numero de columnas: ");
    scanf("%d",&col);
    }while(col<= 0);    
    for (i = 0; i < fil; i++){
        for (j = 0; j <= i; j++){
            printf("%4d ",i*10+j);
        }
        printf("\n");
    }
    return 0;
}