#include <stdio.h>

int main(){ 
    int num1, num2, resultado, resto;
    printf("Digite o dividendo número: ");
    scanf("%d", &num1);
    printf("Digite o divisor número: ");
    scanf("%d", &num2);
    if (num2!=0){
        resultado = num1/num2;
        resto = num1 % num2;
        printf("%d / %d = %d e o resto é %d", num1, num2, resultado, resto);
    }
    else{
        printf("IMPOSSIVEL");
    }
    

}