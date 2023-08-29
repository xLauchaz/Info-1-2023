#include <stdio.h>
#define N 3
#define M 3
int main(void){
    int matriz[N][M];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
                printf("Ingrese el valor de la matriz[%d][%d]: ",i,j);
                scanf("%d",&matriz[i][j]);
        }
        
    }
    printf("\n");
    for (int i = 0; i < N; i++)
    {
        printf("|");
        for (int j = 0; j < M; j++)
        {
            printf(" %d ",matriz[i][j]);
        }
        printf("|\n");
    }
    
    return 0;
}