/*Escreva um programa que carregue um vetor com N números reais, calcule e mostre na tela a quantidade de números negativos e a soma dos números positivos desse vetor.

Entrada: Composta por duas linhas. A primeira linha contém um valor inteiro (N) e a segunda linha contém os números reais.

Saída: única linha contendo a quantidade de negativos e a soma dos positivos, sendo a soma com 1 casa decimal.*/
#include <stdio.h>

int main(){

    int n, positivo=0, negativo=0;

    //Tamanho do vetor
    scanf("%d", &n);
    //declarando vetor
    int vetor[n];

    //preenchendo o vetor
    for(int i=0; i<n; i++){
        scanf("%d", &vetor[i]);
    }

    //varrendo vetor
    for(int i=0; i<n; i++){
        if(vetor[i]<0){
            negativo++;
        }
        else{
            positivo+=vetor[i];
        }
    }

    printf("%d %d", negativo, positivo);

}