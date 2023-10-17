#include <stdio.h>
struct punto_2D
{
    float x;
    float y;
};
struct punto_3D
{
    float x;
    float y;
    float z;
};
int main(void)
{
    struct punto_2D punto1;
    struct punto_3D punto2 = {10.20, 0.3, 5.0};
    //punto1 = punto2; Error

    return 0;
}
