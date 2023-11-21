#include <stdio.h>
#include <unistd.h>
void intro(void)
{
    printf("Bienvenidos! Comnezando en ");
}
int main(void)
{
    int i;
    for(i = 10; i >= 0; --i)
    {
        intro();
        printf("%d \n",i);
        sleep(1);
    }
    return 0;
}