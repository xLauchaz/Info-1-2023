#include <stdio.h>
int main(int argc, char const *argv[])
{
    int nota1, nota2, nota3;
    float promedio;
    printf("Ingrese la nota:  ");
    scanf("%d",&nota1);
    printf("Ingrese la nota:  ");
    scanf("%d",&nota2);
    printf("Ingrese la nota:  ");
    scanf("%d",&nota3);

    promedio = (float)(nota1+nota2+nota3)/3;
    printf("%f\n",promedio);
    return 0;
}
/*ahora puedo hacer esto sin necesidad de utilizar el mouse */
