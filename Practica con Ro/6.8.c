#include <stdio.h>
double hipotenusa(double lado1,double lado2);
int menor(int x, int y, int z);
float intToFloat(int numero);
int main(void)
{
  float x,y;
  int a,b,c;
  printf("Ingrese dos numeros para calcular la hipotenusa: ");
  scanf("%f %f",&x,&y);
  printf("La hipotenusa es: %f",hipotenusa(x,y));
  printf("Ingrese tres numeros para saber cual es el menor: ");
  scanf("%d %d %d",&a,&b,&c);
  printf("El menor es: %d",menor(a,b,c));
  printf("Ingrese un numero entero: ");
  scanf("%d",&a);
  printf("El numero en float es: %f",intToFloat(a));
  return 0;
}
double hipotenusa(double lado1,double lado2)
{
  return (lado1*lado1)+(lado2*lado2);
}
int menor(int x, int y, int z)
{
  if(x<y && x<z)
    return x;
  else if(y<x && y<z)
    return y;
  else
    return z;
}
float intToFloat(int numero)
{
  return (float)numero;
}