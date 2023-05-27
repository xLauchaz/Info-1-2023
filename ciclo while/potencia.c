#include <stdio.h>
int main(void){

	int num1, num2;
	printf("Ingrese el primer numero: ");
	scanf("%d",&num1);
	printf("Ingrese el segundo numero: ");
	scanf("%d",&num2);
	int potencia=1;
	int contador = 0;
	while(contador < num2){
		potencia *= num1;
		contador +=1;
	}
	printf("El resultado es: %d", potencia);
return 0;
}

