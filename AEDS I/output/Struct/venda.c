#include <stdio.h>

typedef struct Venda{
    float preco;
    int pecas;
}Venda;

Venda totalvendas(Venda x, Venda y){
    Venda T;
    T.pecas = x.pecas + y.pecas;
    T.preco =  x.preco + y.preco;
    return T;
}
void dobro (Venda *p){
    p->preco = p->preco*2;
    p->pecas = p->pecas*2;
}

int main(){
    Venda A, B, Total;
    A.pecas=3;
    A.preco=5.20;
    B.pecas=8;
    B.preco=9.45;
    Total=totalvendas(A,B);
    printf("\nPreco total: %.2f\n", Total.preco);
    printf("Pecas total: %d\n\n", Total.pecas);
    dobro(&Total);
    printf("Preco total dobro: %.2f\n", Total.preco);
    printf("Pecas total dobro: %d\n\n", Total.pecas);
}
