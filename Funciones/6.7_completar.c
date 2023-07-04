#include <stdio.h>
//prototipos o declaraciones
int imprimir_primos_hasta(int);
int es_primo(int);
/*int main(void){

    int i, num;
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    printf("Los numeros primos menores que %d son: ", num);
    primos(num);
    return 0;
}
// Definicion
int imprimri_primos_hasta(int n){
    for(int i = 1; i <= n; i++){
        int cont = 0;
        for(int j = 1; j <= i; j++){
            if((i % j) == 0){
                cont++;
            }
        }
        if(cont == 2 || i == 1){
            printf("\n%d ", i);
        }
        
    }
}*/
int main(void){

    int i , num;
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    printf("Los numeros primos menores que %d son: ", num);
    for ( i = 1; i < num; i++)
    {
        if(es_primo(i)){
            printf("%d ", i);
        }
    }
    
    return 0;
}

int es_primo(int n){
    int cont = 0;
    for (int i = 1; i <= n; i++)
    {
        if((n % i) == 0){
            cont++;
        }
    }
    if(cont == 2 || n == 1){
        return 1;
    }else{
        return 0;
    }
    
}