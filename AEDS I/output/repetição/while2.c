#include <stdio.h>
int main(){
    int num, i=0, resto;
    scanf("%d", &num);
    while(num>=0){
        if(num>2){
            for(i=2; i<num; i++){
                resto = num%i;
                if (resto==0){
                    break;
                }
            }
        }
        if(resto==0){
            printf("Nao primo\n");
        }else{
            printf("Primo\n");
        }
        scanf("%d", &num);
    }
}