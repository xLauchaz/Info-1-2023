#include <stdio.h>

struct punto_2D
{
    float x;
    float y;   
};

int main(void)
{
    struct punto_2D p1;
    p1.x = 10.20;
    p1.y = 0.3;
    printf("Las coordenadas del punto son : (%.3f,%3f)\n", p1.x, p1.y);
    return 0;
}