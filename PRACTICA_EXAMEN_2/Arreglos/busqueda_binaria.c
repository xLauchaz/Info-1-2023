#include <stdio.h>
#define TAM 100
int BusquedaBinaria(const int arr[],int ,int, int);
int main(void)
{
    int llave, bajo = 0, alto = TAM - 1, resultado;
    int arr[TAM] = {0};

    //inicializamos el arreglo
    for (int i = 0; i < TAM; i++)
    {
        arr[i] = 2*i;
    }
    printf("Ingrese el numero a buscar: ");
    scanf("%d", &llave);
    resultado = BusquedaBinaria(arr,llave,bajo,alto);  
    if (resultado != -1)
    {
        printf("El numero %d se encuentra en la posicion %d\n", llave, resultado);
    }
    else
    {
        printf("El numero %d no se encuentra en el arreglo\n", llave);
    }
}
int BusquedaBinaria(const int arr[],int llave, int bajo, int alto)
{
    int centro;
    while ( bajo   <= alto)
    {
        centro = (bajo + alto) /2;
        if (llave == arr[centro])
        {
            return centro;
        }
        else if (llave < arr[centro])
        {
            alto = centro - 1;
        }
        else if (llave > arr[centro])
        {
            bajo = centro + 1;
        }
        
    }
    return -1;//devuelve -1 si no se encuentra el elemento
    
}