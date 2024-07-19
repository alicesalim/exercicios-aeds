#include <stdio.h>

int main(){ 
    float b, h, area;
    printf("base: ");
    scanf("%f", &b);
    printf("altura: ");
    scanf("%f", &h);
    area = b*h/2;
    printf("área: %.2f", area);

    return 0;
}