#include <stdio.h>
//Prototipos
float calcularArea(float ,float );
float calcularPerimetro(float ,float );
float imprimirResultados(float, float);
//Función principal
int main(void){
    //Declaración de variables
    float base, altura;
    //Ingreso de datos
    do
    {
        printf("Ingrese la longitud del rectángulo: ");
        scanf("%f", &base);
        printf("Ingrese la altura del rectángulo: ");
        scanf("%f", &altura);
        if (base < 0 || altura < 0)
        {
            printf("\x1b[31m""Uno o más valores ingresados son negativos, por favor ingrese valores positivos.\n""\x1b[0m");
        }
        
    } while (base <= 0 || altura <= 0);
    //Llamado a funcion
    imprimirResultados(calcularArea(base,altura),calcularPerimetro(base,altura));
}
//Funcion que calcula el area
float calcularArea(float b, float h){
    return b*h;
}
//Funcion que calcula el perimetro
float calcularPerimetro(float b, float h){
    return 2*(b+h);
}
//Funcion que imprime los resultados
float imprimirResultados(float a, float p){
    printf("El área del rectángulo es: %.2f\n", a);
    printf("El perímetro del rectángulo es: %.2f\n", p);   
}