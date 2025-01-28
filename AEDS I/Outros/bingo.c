//procedimento: cadastra as n cartelas (matriz quadrada) OK
//procedimento: receber os u numeros sorteados OK
//função: calcular pontos da cartela, quantos numeros de U estao em cada cartela?
//procedimento: imprime o total de pontos de cada cartela
//função main: aciona os procedimentos e funções

#include <stdio.h>
#include <stdlib.h>

//declarando funções e procedimentos
void cadastro(int a, int b);
void numeros_sorteados(int a);
//int calcular_pontos(int );
//void print_pontos

int main(){
    int N, M, U;
    printf("Numero de cartelas: ");
    scanf("%d", &N);
    printf("quantos numeros: ");
    scanf("%d", &M);
    cadastro(N, M);
    printf("quantos numeros sorteados: ");
    scanf("%d", &U);
    numeros_sorteados(U);
    return 0;
}

void cadastro(int a, int b){
    int **ptrN=(int**)malloc(a*sizeof(int*));
    for(int i=0; i<a; i++){
        ptrN[i]=(int*)malloc(b * sizeof(int));
    }
    for(int i=0;i<a;i++){
        for(int j=0; j<b; j++){
            scanf("%d", &ptrN[i][j]);
        }
    }
}

void numeros_sorteados(int a){
    int *ptrU;
    ptrU=(int*)malloc(a*sizeof(int));
    for(int i=0; i<a; i++){
        scanf("%d", &ptrU[i]);
    }
}

int pontos(**p, *p2){
    for(int i=0; i<a; i++){
        ptrN[i]=(int*)malloc(b * sizeof(int));
    }
    for(int i=0;i<a;i++){
        for(int j=0; j<b; j++){
            if(ptrN[i][j]);
        }
    }
}