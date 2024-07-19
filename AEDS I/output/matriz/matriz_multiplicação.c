#include <stdio.h>
#include <stdlib.h>

int main(){

//matriz 1
    int nlin_1, ncol_1;
    printf("\nNúmero de linhas: ");
    scanf("%d", &nlin_1);
    printf("\nNúmero de colunas: ");
    scanf("%d", &ncol_1);
    int matriz_1[nlin_1][ncol_1];

    for(int i=0; i<nlin_1; i++){
        for(int j=0; i<ncol_1; i++){
            matriz_1[i][j]=rand()%10;
        }
    }

//matriz 2
    int nlin_2, ncol_2;
    printf("\nNúmero de linhas: ");
    scanf("%d", &nlin_2);
    printf("\nNúmero de colunas: ");
    scanf("%d", &ncol_2);
    int matriz_2[nlin_2][ncol_2];

    for(int i=0; i<nlin_2; i++){
        for(int j=0; i<ncol_2; i++){
            matriz_2[i][j]=rand()%10;
        }
    }

//condicao
    if(ncol_1!=nlin_2){
        printf("Não é possível fazer a multiplicação!");
    }else{
        int matriz_multiplicacao[nlin_1][ncol_2];
        for(int i=0; i<nlin_1;i++){
            for(int j=0; j<ncol_2; j++){
                matriz_multiplicacao[i][j]=0;
                for(int k=0; k<ncol_1; k++){
                    matriz_multiplicacao[i][j] += matriz_1[i][k] * matriz_2[k][j];
                }

            }
        }
        //mostrando a matriz multiplicação
        for(int i=0; i<nlin_2; i++){
             printf("\n");
            for(int j=0; j<ncol_2; j++){
               printf("%d\t", matriz_multiplicacao[i][j]);
            }
        }
    }

}