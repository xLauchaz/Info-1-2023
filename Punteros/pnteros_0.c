#include <stdio.h>

int main(void){
    
    int num = 100;
    //Para declarar un puntero usamos *.
    int *pnum;
    //asignamos direccion de memoria de num en punteros.

    pnum = &num;
    printf("%d\n",num);
    printf("%d\n",*pnum);
    return 0;
}