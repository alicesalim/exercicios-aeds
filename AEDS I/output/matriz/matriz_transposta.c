#include <stdio.h>
#include <stdlib.h>

int main(){
    int nlin, ncol, i, j;

    //declarando matriz
    printf("numero de linhas: ");
    scanf("%d", &nlin);
    printf("\nnumero de colunas: ");
    scanf("%d", &ncol);
    int matriz[nlin][ncol];

    //semente
    //srand(time(NULL));
    printf("\n");

    //preenchendo matriz
    for(i=0;i<nlin;i++){
        for(j=0; j<ncol;j++){
           matriz[i][j]=rand()%10;
        }
    }

    //matriz normal
    for(i=0;i<nlin;i++){
        for(j=0; j<ncol;j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    //matriz transposta
    for(i=0;i<ncol;i++){
        for(j=0; j<nlin;j++){
            printf("%d\t", matriz[j][i]);
        }
        printf("\n");
    }

}