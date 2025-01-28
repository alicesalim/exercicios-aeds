#include <stdio.h>
#include <string.h>

int palindromo(char *a);

int main(){

    char linha[300];
    fgets(linha, sizeof(linha), stdin);

    while(strcmp(linha, "FIM\n") != 0){

            if(palindromo(linha)==0){
                printf("SIM\n");
            }else{
                printf("NAO\n");
            }
            fgets(linha, sizeof(linha), stdin);
        }
    return 0;
}
 
int palindromo(char *a) {
    //tamanho da string menos um para desconsiderar o \n
    int tam = strlen(a) - 1;
    int indice = 0;
    int fim = tam-1;

    while (indice < fim) {
        if (a[indice] != a[fim]) {
            return 1; // Não é um palíndromo
        }
        indice++;
        fim--;
    }

    return 0; // É um palíndromo
}
