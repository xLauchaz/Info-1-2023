#include <stdio.h>

void incrementa(int a[]){
    a[0]++;
    printf("temp: %d\n",a[0]);
}
int main(void)
{
    int temp[10] = {5,5,5};
    printf("temp: %d\n",temp[0]);
    incrementa(temp);
    printf("temp: %d\n",temp[0]);
    return 0;
}
