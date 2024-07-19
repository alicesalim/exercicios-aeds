#include <stdio.h>
int main(){
    int ni, nj, somalinha, somacoluna, i, j;
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
        somalinha = 0;
        for(int j=0;j<nj;j++){
            somalinha += matriz[i][j];
        }
        printf("\n Soma linha %d é %d", i, somalinha);
    }
    for(j=0;j<nj;j++){
        somacoluna = 0;
        for( i=0;i<ni;i++){
            somacoluna += matriz[j][i];
        }
        printf("\n Soma coluna %d é %d", j, somacoluna);
    }
}