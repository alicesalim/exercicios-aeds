#include <stdio.h>

int main(){
    int n;
    printf("insira sua idade: ");
    scanf("%d", &n);

    if((n>=5)&&(n<=7)){
        printf("INFANTIL");
    }else if((n>=8)&&(n<=12)){
        printf("JUVENIL");
    }else if((n>=13)&&(n<=19)){
        printf("ADOLESCENTE");
    }else if((n>=20)&&(n<=60)){
        printf("ADULTO");
    }else if((n>60)){
        printf("SENIOR");
    }else{
            printf("IDADE INVALIDA");
        }
}