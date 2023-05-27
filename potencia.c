#include <stdio.h>
#include <math.h>
int main(void)
{
    float num1, num2, res;
    scanf("%f",&num1);
    scanf("%f",&num2);
    res = pow(num1,num2);
    printf("El resultado es: %f", res);
    return 0;
}
