#include <stdio.h>
int main(){
    int ni, nj, somadiagonal=0, somadiagonal2=0, trianguloinferior=0, i, j;
    printf("linhas: ");
    scanf("%d", &ni);
    printf("\ncolunas: ");
    scanf("%d", &nj);
    int matriz[ni][nj];
    //entrada de dados da matriz
    for( i=0;i<ni;i++){
        for( j=0;j<nj;j++){
            printf("Digite o conteudo da linha %d coluna %d: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    //impressão dados matriz
    for( i=0;i<ni;i++){
        for(int j=0;j<nj;j++){
            if(i==j){
              somadiagonal += matriz[i][j];  
            }
        }
    }
    printf("\n Soma diagonal é %d", somadiagonal);

    for( i=0;i<ni;i++){
        for(int j=0;j<nj;j++){
            if(i+j==(nj-1)){
              somadiagonal2 += matriz[i][j];  
            }
        }
    }
    printf("\n Soma diagonal 2 é %d", somadiagonal2);

    for( i=0;i<ni;i++){
        for(int j=0;j<nj;j++){
            if(i>j){
              trianguloinferior += matriz[i][j];  
            }
        }
    }
    printf("\n Soma triangulo inferior 2 é %d", trianguloinferior);


}