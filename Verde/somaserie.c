#include <stdio.h>
int main(){
    int i, repeticoes;
    float soma=1;
    scanf("%d", &repeticoes);
    for(i=2;i<=repeticoes;i++){
        soma = soma + (((i*2.0)-1)/(i));
    }
    printf("%.2f", soma);
}