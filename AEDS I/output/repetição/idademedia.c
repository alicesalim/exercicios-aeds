#include <stdio.h>
int main(){
    int idade, soma=0, media, cont=0;
    printf("Digite uma idade: ");
    scanf("%d", &idade);
    while(idade>=0){
        soma=idade+soma;
        printf("Digite outra idade: ");
        scanf("%d", &idade);
        cont++;
    }
    if(cont!=0){
        media=soma/cont;
        printf("media: %d\n", media);
        printf("foram digitadas %d idades", cont);
    }else{
        printf("Não foram inseridas idades validas");
    }
}
