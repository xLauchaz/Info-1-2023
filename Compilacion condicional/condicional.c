#define IMPRIMIR
int main(void){
    printf("Este mensaje se imprime siempre\n");
    #ifndef IMPRIMIR 
        printf("Este mensaje depende de #IMPRIMIR");
    #endif
}