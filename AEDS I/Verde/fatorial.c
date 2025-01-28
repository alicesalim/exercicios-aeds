#include <stdio.h>
int main(){
    int num, fatorial=1, i;
    scanf("%d", &num);
    for(i=2;i<=num;i++){
        fatorial = fatorial*i;
    }
    printf("%d", fatorial);
}