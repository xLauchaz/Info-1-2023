#include <stdio.h>

int main(void){
    int i,j;
    for(i = 0; i < 10 ;i++){
        for(j = 0;j<10;j++){
            printf("%2d ",i*10+j);
        }
        printf("\n");
    }
    return 0;
}