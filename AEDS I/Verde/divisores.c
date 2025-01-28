#include <stdio.h>
int main(){
    int num, i, resto,cont=0;
    scanf("%d", &num);
    for(i=1;i<=num;i++){
        resto = num%i;
        if(resto==0){
            cont++;
        }
    }
    printf("%d", cont);
}