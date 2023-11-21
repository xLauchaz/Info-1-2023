#include <stdio.h>

void suma(int a, int b);
void resta(int a, int b);
void mult(int a,int b);

int main()
{
  int eleccion;
  void (*f[3])(int, int) = {suma,resta,mult};
  do
  {
    printf("Ingrese un numero entre 0 y 2, 3 para salir: ");
    scanf("%d", &eleccion);
  } while (eleccion < 0 || eleccion >= 3);
  (*f[eleccion])(eleccion,eleccion);
  return 0;
}
void suma(int a, int b)
{
  printf("Usted ingresó a suma");
}
void resta(int a, int b)
{
  printf("Usted ingresó a resta");
}
void mult(int a, int b)
{
  printf("Usted ingresó a multiplicacion");
}