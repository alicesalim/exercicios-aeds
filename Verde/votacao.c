#include <stdio.h>
int main(){
    int voto, c1=0, c2=0, c3=0, c4=0, nulo=0, branco=0; 
    float percent;
    do{
        scanf("%d", &voto);
        if(voto==1){
        c1++;
        }else if(voto==2){
            c2++;
        }else if(voto==3){
            c3++;
        }else if(voto==4){
            c4++;
        }else if(voto==5){
            nulo++;
        }else if(voto==6){
            branco++;
        }
    }while(voto!=0);
    percent = (branco*100.0)/(c1+c2+c3+c4+nulo+branco);
    printf("%d %d %d %d\n%d\n%.2f", c1,c2,c3,c4,nulo,percent);
}