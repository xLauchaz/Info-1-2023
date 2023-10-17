#include <stdio.h>
#define TAM 30

int main(void)
{ 
    int dni[TAM];
    float prom[TAM];

    cargar_dni_y_promedio(dni, prom,TAM);
    ordenar_por_dni(dni, prom,TAM);
}
void ordenar_por_dni(int *dni, float *prom, int tam)
{
    int i, j, auxdni;
    float auxprom;
    for (i = 0; i < tam - 1; i++)
        for (j = i + 1; j < tam; j++)
            if (dni[j] > dni[i])
            {
                auxdni = dni[j];
                dni[j] = dni[j+i];
                dni[j+i] = auxdni;
                auxprom = prom[j];
                prom[j] = prom[j+i];
                prom[j+i] = auxprom;
            }
}