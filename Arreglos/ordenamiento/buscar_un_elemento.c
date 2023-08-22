#include <stdio.h>
#define TAM 10
int main(void){

    /*resolver
    1. ingresar tam elementos en un arreglo de enteros
    2. solicitar al usuario un numero
    3. buscar ese numero dentro del arreglo. si existe, indicar su posicion (indice)*/

    int arreglo[TAM];
    int num, pos = -1;
    for (int i = 0; i < TAM; i++)
    {
        printf("Ingrese un numero a almacenar: ");
        scanf("%d",&arreglo[i]);
    }
    printf("Ingrese un numero: ");
    scanf("%d",&num);
    for(int i=0; i< TAM; i++){
        if(arreglo[i]==num){
            printf("El numero %d se encuentra en la posicion %d\n",num,i);
            pos = 1;
        }        
    }
    if (pos == -1)
    {
        printf("El numero %d no se encuentra en el arreglo\n",num);
    }
    
    
    
    return 0;
}