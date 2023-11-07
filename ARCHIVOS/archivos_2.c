#include <stdio.h>
#include <string.h>
#define TAM 1000
// Datos de https://www.kaggle.com/tinnqn/precios-claros-precios-de-argentina/
// Buscar el producto más caro y el más barato
// Imprimir su nombre y el precio

int main(void)
{

  FILE *fPtr;
    float precio;
    float max = 0, min;
    long int codigo;
    char nombre[300], nombre_max[300],nombre_min[300];
  fPtr = fopen("precios_parseados_2.csv", "r");

  if (fPtr == NULL){
    printf("El archivo no se abrió corréctamente\n");
  } else {
    if (!feof(fPtr))
    {
        fscanf(fPtr,"%f,%ld,%s\n",&precio,&codigo,nombre);
        min = precio;
        
    }
    
    while (!feof(fPtr)){
        fscanf(fPtr, "%f,%ld,%s\n", &precio,&codigo,nombre);
        printf("%f %ld %s\n", precio, codigo, nombre);
        for (int i = 0; i < TAM; i++)
        {
            if (precio > max)
            {
                max = precio;
                strcpy(nombre_max,nombre);
            }
            if (precio < min)
            {
                min = precio;
                strcpy(nombre_min,nombre);
            }
            
        }
    }
    puts("");
    printf("El precio de %s es el maximo: %f\n",nombre_max, max);
    printf("El precio de %s es el minimo: %f\n",nombre_min,min);
    fclose(fPtr);

  }

  return 0;
}