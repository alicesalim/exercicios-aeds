#include <stdio.h>
#include <math.h>

int main(){
    // declarar númericos
    float a, b, c, delta, resultado1, resultado2, raiz;

    // ler a
    //printf("Digite o valor de a: ");
    scanf("%f", &a);
    //ler b
    //printf("Digite o valor de b: ");
    scanf("%f", &b);
    //ler c
    //printf("Digite o valor de c: ");
    scanf("%f", &c);

    // testar se delta é <= 0
    delta = b*b-4*a*c;
    printf("%.1f ", delta);

    // calcular raizes
    if (delta==0) {
        resultado1 = (-b)/2*a;
        printf("%.2f", resultado1);
        
    } else if ((delta<0) || (a==0) || (a==b) || (a==0)) {
        printf(" Nao existem raizes");
        
    } else {
        raiz = sqrt(delta);
        resultado1 = ((-b)+raiz)/2*a;
        resultado2 = ((-b)-raiz)/2*a;
        printf("%.1f %.1f", resultado1, resultado2);
    }
    
    return 0;

}