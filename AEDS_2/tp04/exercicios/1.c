#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[20];
    int poder;
    int matou;
    int morreu;
}Deuses;

int main(){
    int n;
    scanf("%d", &n);
    Deuses *deus = (Deuses *)malloc(n * sizeof(Deuses));

    for(int i=0; i<n; i++){
        scanf("%s", deus[i].nome);
        scanf("%d", &deus[i].poder);
        scanf("%d", &deus[i].matou);
        scanf("%d", &deus[i].morreu);
    }
    Deuses ganhador = deus[0];

    for(int i=1; i<n-0; i++){
        if(deus[i].poder>ganhador.poder){
            ganhador = deus[i];
        }else if(deus[i].poder==ganhador.poder){
            if(deus[i].matou>ganhador.matou){
                ganhador = deus[i];
            }else if(deus[i].matou==ganhador.matou){
                if(deus[i].morreu<ganhador.morreu){
                    ganhador = deus[i];
                }else if(deus[i].morreu==ganhador.morreu){
                    if(strcmp(deus[i].nome, ganhador.nome)<0){
                        ganhador = deus[i];
                    }
                }
            }
        }
    }

    printf("%s", ganhador.nome);
}
