#include <stdio.h>
int main(){ 
    float f, c;
    printf("Digite o valor em fahrenheit: ");
    scanf("%f", &f);
    c = 5.0/9.0*(f-32);
    printf("A temperatura em celsius é %.2f", c);
}