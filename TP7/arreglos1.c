#include <stdio.h>
#define TAM 100
void ingreso_de_datos(int cod[],double pre[]);
int validacion_cod(void);
double validacion_pre(void);
void imprimir_datos(int cod[], double pre[]);
void ordenamiento_datos(int cod[],double pre[]);
void mas_caro_y_barato(int cod[],double pre[]);
void mas_caros_y_baratos(int cod[],double pre[]);
int main(void){
    int codigos[TAM];
    double precios[TAM];
    ingreso_de_datos(codigos,precios);
    imprimir_datos(codigos,precios);
    ordenamiento_datos(codigos,precios);
    mas_caro_y_barato(codigos,precios);
    mas_caros_y_baratos(codigos,precios);
    return 0;
}
void ingreso_de_datos(int cod[],double pre[]){
    for (size_t i = 0; i < TAM; i++)
    {
        cod[i] = validacion_cod();
        pre[i] = validacion_pre();
    }
}
int validacion_cod(void){
    int n;
    do
    {
        printf("Ingrese el codigo de barra del producto: ");
        scanf("%d", &n);

    } while (n <= 0 );
    return n;
}
double validacion_pre(void){
    double n;
    do
    {
        printf("Ingrese el precio del producto: ");
        scanf("%lf", &n);
    } while (n < 0);
    return n;
}
void imprimir_datos(int cod[],double pre[]){
    printf("\n\nLista de precios\n");
    printf("----------------------------\n%s%13s\n","Codigos","Precios");
    for (int i = 0; i < TAM; i++)
    {
        printf("%4d%17f\n",cod[i],pre[i]);        
    }
    printf("----------------------------\n");

}
void ordenamiento_datos(int cod[], double pre[]){
    double auxPrecio;
    int auxCodigo;
    for(int i = 0; i < TAM-1; i++){
        for(int j = i+1; j < TAM; j++){
            if(pre[i] < pre[j]){
                auxPrecio = pre[i];
                pre[i] = pre[j];
                pre[j] = auxPrecio;

                auxCodigo = cod[i];
                cod[i] = cod[j];
                cod[j] = auxCodigo;
            }
        }
    }
}
void mas_caro_y_barato(int cod[],double pre[]){
     //impresion del mas caro
    printf("\nProducto mas caro:\n");
    printf("\nCodigo: %d\tPrecio: %.2f\n----------------------------\n", cod[0], pre[0]);
    //impresion del mas barato
    printf("\nProducto mas barato:\n");
    printf("Codigo: %d\tPrecio: %.2f\n----------------------------\n", cod[TAM-1], pre[TAM-1]);
   
}
void mas_caros_y_baratos(int cod[],double pre[]){
    printf("\n\n3 productos mas caros:\n\n");
    for(int i = 0; i < 3; i++){
        printf("%d° Codigo: %d\tPrecio: %.2f\n",i+1, cod[i], pre[i]);
    }
    printf("----------------------------\n");
    //impresion de los 3 mas baratos
    printf("\n\n3 productos mas baratos:\n\n");
    for(int i = TAM-1; i > TAM-4; i--){
        printf("%d° Codigo: %d\tPrecio: %.2f\n",-i+TAM, cod[i], pre[i]);
    }
    printf("----------------------------\n");
}