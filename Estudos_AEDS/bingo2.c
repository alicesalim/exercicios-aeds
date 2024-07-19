//procedimento: cadastra as n cartelas (matriz quadrada) OK
//procedimento: receber os u numeros sorteados 
//função: calcular pontos da cartela, quantos numeros de U estao em cada cartela?
//procedimento: imprime o total de pontos de cada cartela
//função main: aciona os procedimentos e funções

#include <stdio.h>

void cadastrar_cartelas(int a, int b, int matriz[a][b]);
void numeros_sorteados(int a);

int main(){
    int n, m, u;
    scanf("%d", &n);
    scanf("%d", &m);
    int matriz[n][m];
    cadastrar_cartelas(n,m, matriz[n][m]);
    scanf("%d", &u);
}

void cadastrar_cartelas(int a, int b, int matriz[a][b]){
    int *ptr;
    for(int i=0; i<a; i++){
        ptr=matriz[i][0];
        for(int j=0; j<b; j++){
            scanf("%d", *ptr);
            ptr++;
        }
    }
}