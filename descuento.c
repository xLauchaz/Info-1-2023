#include <stdio.h>
int main(int argc, char *argv[]) {
	float compra, descuento = 0, gasto;
	
	printf("Ingrese el monto de la compra:");
	scanf("%f",&compra);
	if(compra >= 1000){
		descuento = 0.2*compra;
		gasto = compra - descuento;
		printf("Su descuento es de $%.2f\n", descuento);
		printf("Su total a pagar es de $%.2f\n", gasto);
	}
	else{
		printf("debe pagar :%.2f\n",compra);
	}
	
	
	return 0;
}

