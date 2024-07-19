#include <stdio.h>
int main(){
    int num=0, cont5=0,contn=-1;
    while(num>-1){
        scanf("%d", &num);
        if(num==5){
            cont5++;
        }
        contn++;
    }
    printf("%d %d", contn, cont5);
}