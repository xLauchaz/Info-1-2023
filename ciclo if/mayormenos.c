#include <stdio.h>

int main(int argc, char *argv[]) {
	int num1,num2,suma,mult;
	printf("Ingrese el primer numero:");
	scanf("%d",&num1);
	printf("Ingrese el segundo numero:");
	scanf("%d",&num2);
	
	if(num1 > num2){
		suma = num1 + num2;
		printf("La suma de los numeros es: %d", suma);
	}
	else if(num1 < num2){
		mult = num1 * num2;
		printf("El priducto de los numeros es: %d", mult);
	}
	else{
		printf("Los numeros son iguales");
	}
	return 0;
}

