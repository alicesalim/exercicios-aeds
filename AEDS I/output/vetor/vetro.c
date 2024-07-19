#include <stdio.h>
int main(){
    int vetor[5], soma=0, media;
    for(int i=0; i<10; i++){
        printf("Digite o conteudo da posicao %d", i);
        scanf("%d", &vetor[1]);
    }
    for(int i=0; i<10; i++){
        printf("\n contrudo da posicao %d é %d", i, vetor[i]);
    }
    for(int i=0; i<10; i++){
        soma = soma+vetor[i];
    }
    media = soma/10;
    printf("%d", media);
}