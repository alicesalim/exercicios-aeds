#include <stdio.h>
void soma_dobro(int *a, int*b, int*soma);
int main(){
    int x, y, res;
    x=5;
    y=3;
    soma_dobro(&x,&y,&res);
    printf("\nA soma dos numeros %d e %d = %d", x, y, res);
    return 0;
}

void soma_dobro(int*a, int*b, int*soma){
    *a=2*(*a);
    *b=2*(*b);
    *soma = *a+*b;

}