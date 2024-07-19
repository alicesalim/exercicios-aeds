#include <stdio.h>
int main(){
    int inicio, fim, passo;
    printf("Digite o primneiro numero: ");
    scanf("%d", &inicio);
    printf("Digite o ultimo numero: ");
    scanf("%d", &fim);
    printf("Digite o primneiro numero: ");
    scanf("%d", &passo);
    if(inicio<fim){
        while(inicio<=fim){
        printf("\n%d",inicio);
        inicio=inicio+passo;
    }}else{
        while(inicio<=fim){
        printf("\n%d",inicio);
        fim=fim-passo;
    }
}}