#include <stdio.h>
#include <math.h>
#define TAM 10
struct punto_2D
{
    float x;
    float y;   
};
void imprimir_punto_mas_lejano(struct punto_2D* arreglo);
int main(void)
{
    struct punto_2D puntos[TAM] = {
        {1.1,3.2},
        {3.5,2.4},
        {3.4,1.1},
        {3.3,2.3},
        {4.5,1.9},
    };
    for(int i = 0; i < TAM; i++)
    {
        printf("puntos[%d] x:%f y:%f\n",i,puntos[i].x,puntos[i].y);
    }
    imprimir_punto_mas_lejano(puntos);

    return 0;
}
void imprimir_punto_mas_lejano(struct punto_2D* arreglo)
{
    //creo arreglo para distancias
    float mod[TAM] = {0};
    //cargo las distancias en el arreglo
    for (int i = 0; i < TAM; i++)
    {
        mod[i] = sqrt(pow(arreglo[i].x,2)+pow(arreglo[i].y,2));
    }
    float max;
    int index_max = 0;
    max = mod[index_max];
    for (int i = 0; i < TAM; i++)
    {
        if (mod[i]>max)
        {
            max = mod[i];
            index_max = 0;
        }
        
    }
    printf("Max vale: %f", max);
    printf("El punto es: %f, %f", arreglo[index_max].x,arreglo[index_max].y);
    
}