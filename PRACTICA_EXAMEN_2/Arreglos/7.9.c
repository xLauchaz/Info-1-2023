#include <stdio.h>
#define N 5
#define M 5

int main(void)
{
  int n,m;
  int a[N][M]={{0},{0}};
  printf("Ingrese las dimensiones de su arreglo en filas y columnas: ");
  scanf("%d %d",&n,&m);
  if ((n<0||n>N)||(m<0||m>M))
  {
    do
    {
      printf("Error\n");
      printf("Ingrese nuevamente las dimensiones de su arreglo");
      scanf("%d %d",&n,&m);
    } while ((n<0||n>N)||(m<0||m>M)); 
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      printf("Ingrese el valor de [%d][%d]",i,j);
      scanf("%d",&a[i][j]);
    }
    
  }
  printf("Su arreglo es\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      printf("[%3d] ",a[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}