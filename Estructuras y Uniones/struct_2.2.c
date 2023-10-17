#include <stdio.h>
struct punto_2D
{
    float x;
    float y;   
};
int main(void)
{
    struct punto_2D p1 = {10.20, 0.3};
    struct punto_2D p2 = {33.2, 23.12};
    printf("Las coordenadas del punto son : (%.3f,%.3f)\n", p1.x, p1.y);
    printf("Las coordenadas del punto son : (%.3f,%.3f)\n", p2.x, p2.y);
    printf("Asigna\n");
    p1 = p2;
    printf("Las coordenadas del punto son : (%.3f,%.3f)\n", p1.x, p1.y);
    printf("Las coordenadas del punto son : (%.3f,%.3f)\n", p2.x, p2.y);
    return 0;
}