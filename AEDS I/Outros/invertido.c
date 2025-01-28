#include <stdio.h>
#include <stdlib.h>

void invertido(int a, int b);

int main(){
    int n;
    scanf("%d", &n);
    invertido(n, 0);
}

void invertido(int a, int b){
    if (a==0){
        printf("%d", b);
    }else{
        b= b*10 + (a%10);
        a = a/10;
        invertido(a, b);
    }
}