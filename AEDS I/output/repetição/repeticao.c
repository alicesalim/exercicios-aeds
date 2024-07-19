#include <stdio.h>
int main(){
    int num, i, resto=1;
    scanf("%d", &num);
    if(num>2){
        for(i=2; i<num; i++){
        resto = num%i;
        if (resto==0){
            break;
        }
    }
}

if(resto==0){
    printf("Nao primo");
}else{
    printf("Primo");
} 

}
