#include <stdio.h>
int main(int argc, char const *argv[])
{
  //declaramos las variables
  float nota,mas_alta = 0,mas_baja = 100,promedio,total = 0;
  int cant_est;
  //pedimos el ingreso de notas
  printf("%s","Ingrese la cantidad de estudiantes a evaluar:");
  scanf("%d",&cant_est);
  //comprobacion de alumnos
  while (cant_est <= 0)
  {
     printf("%s","ERROR, Ingrse un numero positivo mayor a cero:");
     scanf("%d",&cant_est);
  }
  for (int i = 1;i <= cant_est;i++)
  {
    //comprobacion de las notas
    do
    {
      printf("%s%d%s","Ingrese la nota del estudiante",i,":");
      scanf("%f",&nota);
    } while (nota <= 0 || nota > 100);
    //suma de las notas
    total += nota;

    //comparar notas

    if (nota >= mas_alta)
    {
      mas_alta = nota; 
    }
    if (nota <= mas_baja)
    {
      mas_baja = nota;
    }
  } 
  promedio = total/cant_est;
  printf("%s%.2f\n","El promedio de notas es:",promedio);
  printf("%s%.2f\n","La nota mas alta es:",mas_alta);
  printf("%s%.2f\n", "La nota mas baja es:",mas_baja);
  return 0;
}
