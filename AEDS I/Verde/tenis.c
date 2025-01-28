#include <stdio.h>
int main(){
  char resultado;
  int cont=0, i;
  for(i=0;i<6;i++){
   scanf(" %c", &resultado);
    if(resultado=='V'){
      cont++;
    }
  }
  if((cont==5)||(cont==6)){
    printf("1");
  }else if((cont==3)||(cont==4)){
    printf("2");
  }else if((cont==2)||(cont==1)){
    printf("3");
  }else{
    printf("-1");
  }
}