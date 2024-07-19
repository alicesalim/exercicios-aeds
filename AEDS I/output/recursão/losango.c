#include <stdio.h>

void losango(int a, int b);

int main(){
    int n1;
    scanf("%d", &n1);
    losango(n1, n1);
}

void losango(int a, int b){
    //par
    b=(a/2)-1;
    if(a%2==0){
        for(int i=0; i<b; i++){
            printf("b");
            losango(a, b);
        }
    printf("*");
    }
    

     
}