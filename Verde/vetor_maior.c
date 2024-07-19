/*Faça um algoritmo que leia um vetor de N posições de números inteiros e imprima o maior elemento do vetor e sua posição no vetor. 
Caso exista mais de um elemento cujo valor seja o maior dentre todos, imprima a posição do último elemento encontrado. N é lido pelo algoritmo.
Entrada: A entrada é composta por duas linhas. A primeira linha contém um inteiro que representa o tamanho do vetor (N). 
A segunda linha contém N inteiros que representa o conteúdo do array.
Saída: Um única linha contendo o maior elemento e sua respectiva posição.*/
#include <stdio.h>
int main(){
    int n, posicao=0;
    scanf("%d", &n);
    int vetor[n], i, maior;
    for(i=0;i<n;i++){
        scanf("%d", &vetor[i]);
    }
    maior = vetor[0];
    for(i=0;i<n;i++){
        if(vetor[i]>=maior){
            maior = vetor[i];
            posicao = i;
        }
    }
    printf("%d %d", maior, posicao);

}