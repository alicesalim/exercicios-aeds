#include <stdio.h>
int main(){
    float salario, cont, media, soma;
    salario=0;
    cont=0;
    soma=0;
    while(salario>=0){
        soma=salario+soma;
        cont++;
        printf(" Digite seu salrio: ");
        scanf("%f", &salario);
    }
    cont=cont-1;
    if(cont==0){
        printf("ERROR");
    }else{
        media=soma/cont;
        printf("media: %.2f", media);
    }
}