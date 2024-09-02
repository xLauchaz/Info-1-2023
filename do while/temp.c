#include <stdio.h>

int main(){
  float temp;
  int cont = 0;
  float suma = 0;

  do
  {
    printf("Ingrese la temperatura %d: ", cont+1);
    scanf("%f", &temp);
    if (temp != -1)
    {
      suma += temp;
      cont++;
    }
  } while (temp != -1);
  printf("El promedio de las temperaturas es: %.2f\n", suma/cont);
  return 0;
}