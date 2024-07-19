#include <stdio.h>
int main(){
    int matriz[3][4];
    //entrada de dados da matriz
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            printf("Digite o conteudo da linha %d coluna %d: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    //impressão dados matriz
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}