#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct Colaboradores{
    int codigo;
    char nome[50];
    char email[100];
    int salario;
}Colaboradores;

int menu(){
    int opcao;
    printf("1\n2\n3\n");
    scanf("%d", &opcao);
    return opcao;
}

Colaboradores cadastro(){
    Colaboradores pessoa;
    printf("Codigo: ");
    scanf("%d", &pessoa.codigo);
    getchar();
    printf("nome: ");
    fgets(pessoa.nome, 50, stdin);
    pessoa.nome[strcspn(pessoa.nome, "\n")] = '\0';
    printf("email: ");
    fgets(pessoa.email, 200, stdin);
    pessoa.email[strcspn(pessoa.email, "\n")] = '\0';
    printf("salario: ");
    scanf("%d", &pessoa.salario);
    getchar();
    return pessoa;
}
void salvaColaborador(FILE *arquivo, Colaboradores colaborador) {
    fprintf(arquivo, "Codigo: %d\n", colaborador.codigo);
    fprintf(arquivo, "Nome: %s\n", colaborador.nome);
    fprintf(arquivo, "Email: %s\n", colaborador.email);
    fprintf(arquivo, "Salario: %d\n", colaborador.salario);

}

int main(){
    FILE * arquivo;
    Colaboradores *colaborador = NULL;
    int quantidade = 0;
    //pedindo a opcao que deseja
    int opcao;
    printf("opcao: ");
    scanf("%d", &opcao);

    if(opcao==1){
        arquivo = fopen("nome.txt", "a+");
        colaborador = realloc(colaborador, (quantidade + 1) * sizeof(Colaboradores));
        printf("\nCadastro do colaborador %d:\n", quantidade + 1);
        colaborador[quantidade] = cadastro();
        salvaColaborador(arquivo, colaborador[quantidade]);
        quantidade++;
        fclose(arquivo);
    }

}