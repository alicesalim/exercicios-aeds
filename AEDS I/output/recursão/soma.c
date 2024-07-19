#include <stdio.h>

int multiplicacao(int a, int b);

int main(){
    int n1, n2;
    scanf("%d", &n1);
    scanf("%d", &n2);
    printf("%d", multiplicacao(n1, n2));
}

int multiplicacao(int a, int b){
    if(a==0){
        return 0;
    }
    return b+multiplicacao(a-1, b);
    
}