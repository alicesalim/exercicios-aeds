#include <stdio.h>

int main(){
    // declarando os númericos
    float raio, area;
    // inserir raio
    printf("Insira o valor do raio: ");
    scanf("%f2", &raio);
    //calculando a area
    area = 3.14*raio*raio;
    // escrevendo raio
    printf("O valor da área é: %.2f", area);

    return 0;
}