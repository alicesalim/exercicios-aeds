#include <stdio.h>
#include <stdlib.h>

void preenchevetor(int vetor[], int a);

int main(){
    int n;
    scanf("%d", &n);
    int vet[n];
    preenchevetor(vet, n);
    int *ptr2;
    ptr2=vet;
    for(int i=0;i<n;i++){
        printf("%d", *ptr2);
        ptr2++;
    }
}

void preenchevetor(int vetor[], int a){
    int *ptr;
    ptr=vetor;
    for(int i=0; i<a; i++){
        scanf("%d", ptr);
        ptr++;
    }

}
