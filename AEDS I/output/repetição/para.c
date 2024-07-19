#include <stdio.h>
int main(){
    int num1, intervalo, num2, i;
    printf("Digite o primneiro numero: ");
    scanf("%d", &num1);
    printf("Digite o ultimo numero: ");
    scanf("%d", &num2);
    printf("Digite o primneiro numero: ");
    scanf("%d", &intervalo);
    if(num1<=num2){
        for(i=num1;i<=num2;i=i+intervalo){
        printf("\n%d", i);
    }}else{
        for(i=num1;i<=num2;i=i-intervalo){
        printf("\n%d", i);}
    }
    

    /*for( i=0;i<101;i++){
        printf("\n%d", i);
    }
    for(i=50;i<61;i++){
        printf("\n%d", i);
    }
    for(i=0;i<51;i=i+4){
        printf("\n%d", i);
    }
    for(i=1;i<1025;i=i*2){
        printf("\n%d", i);
    }
    for(i=50;i>0;i--){
        printf("\n%d", i);
    }
    for(i=1024;i<=0;i=i/2){
        printf("\n%d", i);
    }*/

    
}