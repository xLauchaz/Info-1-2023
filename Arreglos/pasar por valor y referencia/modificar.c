#include <stdio.h>
void incrementa(int a){
    a++;
    printf("temp: %d\n",a);
}
int main(int argc, char const *argv[])
{
    int temp = 10;
    printf("temp: %d\n", temp);
    incrementa(temp);
    printf("temp: %d\n", temp);
    return 0;
}
