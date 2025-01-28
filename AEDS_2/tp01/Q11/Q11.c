#include <stdio.h>
#include <string.h>

int palindromo(char *a, int i, int fim);

int main(){

    char linha[300];
    fgets(linha, sizeof(linha), stdin);


    while(strcmp(linha, "FIM\n") != 0){

            if(palindromo(linha, 0, strlen(linha)-1)==0){
                printf("SIM\n");
            }else{
                printf("NAO\n");
            }
            fgets(linha, sizeof(linha), stdin);
            
        }
    return 0;
}
 
int palindromo(char *a, int i, int fim) {
    //tamanho da string menos um para desconsiderar o \n
    if (i >= fim) {
            return 0; //É um palíndromo
    }
    if (a[i] != a[fim]) {
        return 1; // Não é um palíndromo
    }
    return palindromo(a, i + 1, fim - 1);
}