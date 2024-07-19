#include <stdio.h>
#include <math.h>

int main(){

    int n, soma=0, *ptr;
    scanf("%d", &n);

    int vetor[n];

    for(int i=0; i<n; i++){
        scanf("%d", &vetor[i]);
    }
    ptr=&vetor[0];
    for(int i=(n-1); i>0; i--){
        *ptr= *ptr*(pow(2,i));
        soma+=*(ptr);
        ptr++;
    }
    printf("%d", soma);
}