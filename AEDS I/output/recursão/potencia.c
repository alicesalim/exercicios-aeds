//implemente uma função recursivo que, dados dois numeros x e N, calcula xˆN
#include <stdio.h>

int potencia (int , int );

int main(){
    int n1, n2;
    scanf("%d", &n1);
    scanf("%d", &n2);
    printf("%d", potencia(n1, n2));
}

int potencia(int a, int b){
    if(b==0){
        return 1;
    }
    b--;
    return a*potencia(a, b);
}