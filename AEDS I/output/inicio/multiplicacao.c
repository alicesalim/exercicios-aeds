#include <stdio.h>
int main(){
    float num1, num2, resultado;

    printf("Digite o primeiro número: ");
    scanf("%f", &num1);

    printf("Digite o segundo número: ");
    scanf("%f", &num2);

    resultado = (num1+num2)/2;

    printf("A média é igual a %.2f", resultado);
}