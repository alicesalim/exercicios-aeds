#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Carro{
    char marca[100];
    char modelo[100];
    char cor[100];
    int ano;
}Carro;

int menu(){

    int x;
    printf("\n1) Cadastrar carro\n2) Mostrar carros\n3) Alterar ano\n4) Mostrar soma dos anos\n5) Consultar por marca\n6) Remover um carro\n7) Encerrar\n\n");
    scanf("%d", &x);
    getchar();
    return x;
}
void espera(){
    printf("\nPressione ENTER para continuar");
    getchar();
    system("clear");
}
Carro cadastro(){
    Carro x;
    printf("\nDigite a marca do Carro: ");
    fgets(x.marca, 100, stdin);
    x.marca[strcspn(x.marca, "\n")] = '\0';

    printf("\nDigite o modelo do Carro: ");
    fgets(x.modelo, 100, stdin);
    x.modelo[strcspn(x.modelo, "\n")] = '\0';

    printf("\nDigite a cor do Carro: ");
    fgets(x.cor, 100, stdin);
    x.cor[strcspn(x.cor, "\n")] = '\0';

    printf("\nDigite o ano do Carro: ");
    scanf("%d", &x.ano);
    getchar();

    return x;
}

void imprimir(Carro *p, int a){
    printf("\nMarca carro %d: %s", a+1, p[a].marca);
    printf("\nModelo carro %d: %s", a+1, p[a].modelo);
    printf("\ncor carro %d: %s", a+1, p[a].cor);
    printf("\nano carro %d: %d\n", a+1, p[a].ano);
}

int alterarAno(){
    int x;
    printf("Digite o ano correto: ");
    scanf("%d", &x);
    return x;
}

int somaAno(Carro *p){
    int soma=0;
    for(int i=0;i<sizeof(p);i++){
        soma+=p[i].ano;
    }
    return soma;
}

void remover(Carro *p, int x){
    for(int i=x;i<sizeof(p);i++){
        p[i]=p[i-1];
    }
}

int main(){

    int answer, quantidade;
    Carro *ptr;
    quantidade=0;
    ptr=(Carro*)malloc(sizeof(Carro));

    do{
        answer = menu();
        system("clear");
        //cadastro
        if(answer==1){
            quantidade++;
            ptr=(Carro*)realloc(ptr, quantidade*sizeof(Carro));
            ptr[quantidade-1]=cadastro();
        }
        system("clear");
        //imprimir
        if(answer==2){
            for(int i=0; i<quantidade;i++){
                imprimir(ptr, i);
            }
            espera();
        }
        //alterar ano
        if(answer==3){
            int i;
            printf("\nQual o número do carro que deseja alterar o ano? ");
            scanf("%d", &i);
            ptr[i-1].ano=alterarAno();
            system("clear");
        }
        //soma
        if(answer==4){
            int total;
            total=somaAno(ptr);
            printf("A soma é: %d\n", total);
            espera();
        }
        if(answer==5){
            char marca[100];
            printf("\nQual a marca de carro que deseja consultar? ");
            fgets(marca, 100, stdin);
            marca[strcspn(marca, "\n")] = '\0';
            for(int i=0;i<quantidade;i++){
                if(strcmp(ptr[i].marca, marca) == 0){
                    imprimir(ptr, i);
                }
            }
            espera();
        }
        if(answer==6){
            int i;
            printf("Qual carro voce deseja excluir?: ");
            scanf("%d", &i);
            remover(ptr, i-1);
            quantidade--;
            ptr=(Carro*)realloc(ptr, quantidade*sizeof(Carro));
            system("clear");
        }
    }while(answer!=7);
 }