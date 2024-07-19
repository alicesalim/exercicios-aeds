#include <stdio.h>
int main(){
    int num, resto;
    scanf("%d", &num);
    while(num!=0){
        resto = num%10;
        printf("%d", resto);
        num = num/10;
    }
}