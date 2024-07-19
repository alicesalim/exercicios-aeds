#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int menor=0, maior=0;
    int ncol=10;
    int *p, *pMaior=NULL, *pMenor=NULL;
    p = (int*) malloc(10*sizeof(float));
    for(int i=0; i<ncol; i++){
        p[i]=rand()%10;
    }
    int *pAux=p;
    for(int i=0; i<ncol; i++){
        if(*pAux>=maior){
            maior=*pAux;
            pMaior=pAux;
        }
        if(*pAux<=menor){
            menor=*pAux;
            pMenor=pAux;
        }
        pAux++;
    }
    for(int i=0; i<ncol; i++){
        printf("%d\t", p[i]);
    }
    printf("\nmaior %d endereço %p \nmenor %d endereço %p", maior, pMaior, menor, pMenor);

    ncol+=10;
    p = (int*)realloc(p, ncol * sizeof(int));
    for(int i=10; i<ncol; i++){
        p[i]=rand()%10;
    }


    int *pAux2=p;
    for(int i=0; i<ncol; i++){
        if(*pAux2>=maior){
            maior=*pAux2;
            pMaior=pAux2;
        }
        if(*pAux2<=menor){
            menor=*pAux2;
            pMenor=pAux2;
        }
        pAux2++;
    }
    for(int i=0; i<ncol; i++){
        printf("%d\t", p[i]);
    }
    printf("\nmaior %d endereço %p \nmenor %d endereço %p\n", maior, pMaior, menor, pMenor);
    free(p);
}