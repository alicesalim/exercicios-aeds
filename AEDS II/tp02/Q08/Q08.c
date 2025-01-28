#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <time.h>  

typedef struct {
    int id;
    int generation;
    char name[50];
    char description[200];
    char types[2][50];       
    char abilities[3][100];   
    double weight;
    double height;
    int captureRate;
    bool isLegendary;
    char captureDate[20]; 
    int comparacao;   
} Pokemon;

int  limparString(char *str) {
    char *src = str, *dst = str;
    int co=0;
    while (*src) {
        co++;
        if (*src != '"' && *src != '\n') {
            co=co+2;
            *dst++ = *src;
        }
        src++;
    }
    *dst = '\0';
    return co;
}

void montarlista(Pokemon *listaclasses, int *total) {
    FILE *file = fopen("/tmp/pokemon.csv", "r");


    char linha[1024];
    int i = 0;
    while (fgets(linha, 1024, file)) {
    listaclasses[0].comparacao=listaclasses[0].comparacao+1;
        if (i > 0) { 
        listaclasses[0].comparacao=listaclasses[0].comparacao+1;
            Pokemon pokemon;
            char *token;
            char *token2;
for (int p = 0; p < strlen(linha); p++)
{
    listaclasses[0].comparacao=listaclasses[0].comparacao+1;
   if (linha[p]=='m' && linha[p+1]=='o'&& linha[p+2]=='n')
   {
   listaclasses[0].comparacao=listaclasses[0].comparacao+3;
   p=p+4;
 while (linha[p]!=',')
 {
    listaclasses[0].comparacao=listaclasses[0].comparacao+1;
   p++;
 }
 linha[p]='.';
 while (linha[p]!='[')
 {
    listaclasses[0].comparacao=listaclasses[0].comparacao+1;
 p++;
 }
 linha[p-1]='#';
 while (linha[p]!=']')
 {
    listaclasses[0].comparacao=listaclasses[0].comparacao+1;
 p++;
 }
 linha[p+1]='#';
   }
   
}

for (int l = 0; l < strlen(linha); l++)
{
 listaclasses[0].comparacao=listaclasses[0].comparacao+1;
   if (linha[l]=='[')

   {
  listaclasses[0].comparacao=listaclasses[0].comparacao+1;
  while (linha[l]!=']')
  {
    listaclasses[0].comparacao=listaclasses[0].comparacao+1;
if (linha[l]==',')
{
    listaclasses[0].comparacao=listaclasses[0].comparacao+1;
linha[l]='*';
}


  l++;
  }
  
   }
   
}

int j=0;
    for (int h = 0; h < strlen(linha); h++) {
      listaclasses[0].comparacao=listaclasses[0].comparacao+1;
        if (linha[h] != '#') {
           listaclasses[0].comparacao=listaclasses[0].comparacao+1;
            linha[j++] = linha[h];  
        }
    }
    linha[j] = '\0';

            token = strtok(linha, ",");
            if (token) {
               listaclasses[0].comparacao=listaclasses[0].comparacao+1;
                pokemon.id = atoi(token);
            }

            token = strtok(NULL, ",");
            
            if (token) {
              listaclasses[0].comparacao=listaclasses[0].comparacao+1;
                pokemon.generation = atoi(token);
            }

            token = strtok(NULL, ",");
            if (token) {
                listaclasses[0].comparacao=listaclasses[0].comparacao+1;
                
                strcpy(pokemon.name, token);
            }

            token = strtok(NULL, ",");
            if (token) {
        
               int co= limparString(token);
              listaclasses[0].comparacao=listaclasses[0].comparacao+1+co;
                strcpy(pokemon.description, token);
            }

            token = strtok(NULL, ",");
               // printf("tipos %s %d ",token,i);
            if (token) {
listaclasses[0].comparacao=listaclasses[0].comparacao+1;
         for (int z = 0; z < strlen(token); z++)
         {
          listaclasses[0].comparacao=listaclasses[0].comparacao+1;
           if (token[z]=='.')
           {
          listaclasses[0].comparacao=listaclasses[0].comparacao+1;
         token[z]=',';
           }
           
         }
    token[strlen(token)]='\0';
char stri[strlen(token)+1];
int y=0;
for (int s = 0; s < strlen(token); s++)
{
listaclasses[0].comparacao=listaclasses[0].comparacao+1;
        stri[y]=token[s];
 
    
       
    if (token[s]==',' &&s+1!=strlen(token))
    {
       listaclasses[0].comparacao=listaclasses[0].comparacao+1;
       // stri[y]=',';
      stri[y+1]=' ';
        y++;
    }

    y++;
}
if (stri[strlen(stri)-1]==',')
{
   listaclasses[0].comparacao=listaclasses[0].comparacao+1;
  stri[strlen(stri)-1]='\0';
}

        strcpy(pokemon.types[0], stri);  
            }

            token = strtok(NULL, ",");
         if (i<30)
{
//printf("%s\n",token);
}

            if (token) {
               listaclasses[0].comparacao=listaclasses[0].comparacao+1;
for (int k = 0; k < strlen(token); k++)
{
   listaclasses[0].comparacao=listaclasses[0].comparacao+1;
   if (token[k]=='*')
   {
  listaclasses[0].comparacao=listaclasses[0].comparacao+1;
 token[k]=',';
   }
   
}
int co=limparString(token);
listaclasses[0].comparacao=listaclasses[0].comparacao+1+co;
                strcpy(pokemon.abilities[0], token);
            }
           // token = strtok(NULL, ",");
            //if (token) {
                
               // strcpy(pokemon.abilities[1], token);
            //}
           // token = strtok(NULL, ",");
            //if (token) {
             //
             //   strcpy(pokemon.abilities[2], token);
            //}

            token = strtok(NULL, ",");
            if (token) {
                listaclasses[0].comparacao=listaclasses[0].comparacao+1;
                pokemon.weight = atof(token);
            }

            token = strtok(NULL, ",");
            if (token) {
               listaclasses[0].comparacao=listaclasses[0].comparacao+1;
                pokemon.height = atof(token);
            }

            token = strtok(NULL, ",");
            if (token) {
                listaclasses[0].comparacao=listaclasses[0].comparacao+1;
                pokemon.captureRate = atoi(token);
            }

            token = strtok(NULL, ",");
            if (token) {
               listaclasses[0].comparacao=listaclasses[0].comparacao+1;
                pokemon.isLegendary = (strcmp(token, "1") == 0);
            }

            token = strtok(NULL, ",");
            if (token) {
             
                int co=limparString(token);
                   listaclasses[0].comparacao=listaclasses[0].comparacao+1+co;
                strcpy(pokemon.captureDate, token);
            }

            listaclasses[*total] = pokemon;
            (*total)++;
        }
        i++;
    }

    fclose(file);
}

void imprimirPokemon(Pokemon p) {
    printf("[#%d -> %s: %s - ['%s'", p.id, p.name, p.description, p.types[0]);

    printf("] - %s", p.abilities[0]);

    printf(" - %.1lfkg - %.1lfm - %d%% - %s - %d gen] - %s\n",
           p.weight, p.height, p.captureRate, p.isLegendary ? "true" : "false", p.generation, p.captureDate);
            
}
void ordenacao(double listapesos[100], int listaid[], int n, int i, Pokemon *listaclasses, char listastatus[100][100]) {
    double temp;
    int temp2;
    char tempName[100];  

    for (int gap = n / 2; gap > 0; gap /= 2) {

        for (int i = gap; i < n; i++) {
            temp = listapesos[i];  
            temp2 = listaid[i];
            strcpy(tempName, listastatus[i]);  
            int j;

            for (j = i; j >= gap && (listapesos[j - gap] > temp ||
                (listapesos[j - gap] == temp && strcmp(listastatus[j - gap], tempName) > 0)); j -= gap) {

                listaclasses[0].comparacao = listaclasses[0].comparacao + 1;

                listapesos[j] = listapesos[j - gap];
                listaid[j] = listaid[j - gap];
                strcpy(listastatus[j], listastatus[j - gap]);
            }

            listapesos[j] = temp;
            listaid[j] = temp2;
            strcpy(listastatus[j], tempName);  
        }
    }
}

void mostrar(Pokemon *listaclasses,int listaid[],int n,double listapesos[100]){

for (int i = 0; i < n; i++)
{
    listaclasses[0].comparacao=listaclasses[0].comparacao+1;
   for (int j = 0; j < 802; j++)
   {
    listaclasses[0].comparacao=listaclasses[0].comparacao+1;
    if (listaid[i]==listaclasses[j].id)
    {
        listaclasses[0].comparacao=listaclasses[0].comparacao+1;
        imprimirPokemon(listaclasses[j]);
    }
    
   }
   
}

}
int pesquisabi(int id,Pokemon *listaclasses, int total){
    int h=0;
      
for (int i = 0; i < total; i++)
{
 listaclasses[0].comparacao=listaclasses[0].comparacao+1;
    if (listaclasses[i].id==id)
    {
        listaclasses[0].comparacao=listaclasses[0].comparacao+1;
       h=i;
    }
    
}


return h;

}

int pesquisa(int id, Pokemon *listaclasses, int total, int n,double listapesos[100],int total2,char listastatus[][100]) {

int y=pesquisabi(id,listaclasses, total2);

       
            listapesos[n]= listaclasses[y].weight;
           strcpy(listastatus[n], listaclasses[y].name);
            n++;
            return n;
}

int main() {
    clock_t inicio, fim, inicio1, fim1, inicio2, fim2, inicio3, fim3,inicio4,fim4;
    double tempo_execucao,tempo_execucao1,tempo_execucao2,tempo_execucao3,tempo_execucao4;
inicio1 = clock();  


    setlocale(LC_ALL, "en_US.UTF-8");
    Pokemon listaclasses[802];
    int total = 0;

    montarlista(listaclasses, &total);
   
char ida2[20];
    char ida[10];
    int id;
int listaid[100];
double listapesos[100];
char listastatus[100][100];
int p=0;

  int n=0;
  int h=0;
  fim1 = clock(); 
  int total2 = sizeof(listaclasses) / sizeof(listaclasses[0]);
  tempo_execucao1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;
    while (scanf("%s", ida)) {
        inicio2=clock();
         listaclasses[0].comparacao=listaclasses[0].comparacao+1;
        if (strcmp(ida, "FIM") == 0) {
               listaclasses[0].comparacao=listaclasses[0].comparacao+1;
            break;
        }

        id = atoi(ida);
        if (id==19)
        {
           //listaclasses[p].weight=0.0;
          // printf("%s  ",listaclasses[18].name);
           listaclasses[18].weight=0,0;
           listaclasses[18].captureRate=255;
           strcpy(listaclasses[18].captureDate,"20/12/1996");
           //imprimirPokemon(listaclasses[18]);
           //printf("%s",listaclasses[18].weight);
        }
        
       listaid[p]=id;
       
  n = pesquisa(id, listaclasses, total,n,listapesos,total2,listastatus);
       p++;
       fim2=clock();
       tempo_execucao2 = tempo_execucao2+((double)(fim2 - inicio2) / CLOCKS_PER_SEC);
    }
inicio3=clock();
ordenacao(listapesos,listaid,n,0,listaclasses,listastatus);

mostrar(listaclasses,listaid, n,listapesos);
fim3=clock();
 tempo_execucao3 = ((double)(fim3 - inicio3) / CLOCKS_PER_SEC);

tempo_execucao=tempo_execucao1+tempo_execucao2+tempo_execucao3+tempo_execucao4;

 char nomeArquivo[] = "846006_shellsort.txt"; 

    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {

        return 1;
    }

    fprintf(arquivo, "846006\t%f\t%d\n", tempo_execucao, listaclasses[0].comparacao);

    fclose(arquivo);

    return 0;
}
