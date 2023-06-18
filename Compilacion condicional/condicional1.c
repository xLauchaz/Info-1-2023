#define IMPRIMIR
int main(void){
    printf("Este mensaje se imprime siempre\n");
    #ifndef IMPRIMIR 
        printf("Este mensaje depende de #IMPRIMIR\n");
    #else
        printf("Este mensaje no depende de #IMPRIMIR\n");
    #endif
}