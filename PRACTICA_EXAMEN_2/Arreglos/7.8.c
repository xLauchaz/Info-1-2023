#include <stdio.h>
#define N 3
#define M 3

int main(void)
{
  int a[N][M]={{0},{0}};
  printf("Ingrese el arreglo de %d x %d dimensiones\n",N,M);
  for (int i = 0; i < N; i++)
  {
    for(int j=0; j < M; j++)
    {
      printf("Ingrese el elemento [%d][%d] de la matriz: ",i,j);
      scanf("%d",&a[i][j]);
    }
  }
  for (int i = 0; i < N; i++)
  {
    for(int j = 0; j<M;j++)
    {
      printf("[%3d]",a[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}