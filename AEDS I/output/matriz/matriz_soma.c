#include <stdio.h>
#include <stdlib.h>

int main(){
    int nlin, ncol, i, j;

    printf("numero de linhas: ");
    scanf("%d", &nlin);
    printf("\nnumero de colunas: ");
    scanf("%d", &ncol);

// matriz 1
    int matriz[nlin][ncol];
    printf("\n");

    //preenchendo matriz
    for(i=0;i<nlin;i++){
        for(j=0; j<ncol;j++){
           matriz[i][j]=rand()%10;
        }
    }
    for(i=0;i<nlin;i++){
        for(j=0; j<ncol;j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");

//matriz 2
    int matriz2[i][j];

    //preenchendo matriz
    for(i=0;i<nlin;i++){
        for(j=0; j<ncol;j++){
           matriz2[i][j]=rand()%10;
        }
    }
    for(i=0;i<nlin;i++){
        for(j=0; j<ncol;j++){
            printf("%d\t", matriz2[i][j]);
        }
        printf("\n");
    }
    printf("\n");

//matriz soma
    int matrizsoma[i][j];

    //somando
    for(i=0;i<nlin;i++){
        for(j=0; j<ncol;j++){
            matrizsoma[i][j]= matriz[i][j] + matriz2[i][j];
            printf("%d\t", matrizsoma[i][j]);
        }
        printf("\n");
    }



}