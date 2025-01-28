#include <stdio.h>
#include <string.h>


int main() {
 int n;
  scanf("%d", &n);
  getchar();
  char str[n][100];
  char tamanho[100]="";
  char alfabetico[100]="";
  for(int i=0; i<n; i++){
    fgets(str[i], 100, stdin);
    str[i][strcspn(str[i], "\n")] = '\0'; 
  }
  //tamanho
  for(int i=0; i<n; i++){
    if(strlen(str[i])>strlen(tamanho)){
      strcpy(tamanho, str[i]);
    }
  }
  printf("%s\n", tamanho);
  //alfabetico
  for(int i=0; i<n; i++){
    if(strcmp(str[i], alfabetico)>0){
      strcpy(alfabetico, str[i]);
    }
  }
  printf("%s", alfabetico);
  
}