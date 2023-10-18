#include <stdio.h>
union temp_u
{
    int i_temp;
    float f_temp;
};

int main(void)
{
    union temp_u temperatura;
    printf("Asigno la parte entera\n");
    temperatura.i_temp = 10;
    printf("Asigno la parte flotante\n");
    temperatura.f_temp = 10.1;
    printf("Valor de f_temp: %f\n", temperatura.f_temp);
    printf("Valor de i_temp: %d\n", temperatura.i_temp);

}