#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;      // Array dinâmico para armazenar os elementos da fila
    int tamanho;     // Número de elementos na fila
    int capacidade;  // Capacidade máxima atual do array
} Fila;

// Função para criar e inicializar uma nova fila
Fila* criarFila(int capacidadeInicial) {
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    fila->dados = (int*)malloc(capacidadeInicial * sizeof(int));
    fila->tamanho = 0;
    fila->capacidade = capacidadeInicial;
    return fila;
}

// Função para redimensionar o array da fila se necessário
void redimensionarFila(Fila *fila) {
    fila->capacidade *= 2;
    fila->dados = (int*)realloc(fila->dados, fila->capacidade * sizeof(int));
}

// Função para inserir um elemento no final da fila
void inserir(Fila *fila, int valor) {
    if (fila->tamanho == fila->capacidade) {
        redimensionarFila(fila);
    }
    fila->dados[fila->tamanho++] = valor;
}

// Função para remover o primeiro elemento da fila
int remover(Fila *fila) {
    if (fila->tamanho == 0) {
        printf("Erro: A fila está vazia!\n");
        exit(1);
    }
    int valorRemovido = fila->dados[0];
    for (int i = 1; i < fila->tamanho; i++) {
        fila->dados[i - 1] = fila->dados[i];
    }
    fila->tamanho--;
    return valorRemovido;
}

// Função para mostrar todos os elementos da fila
void mostrar(Fila *fila) {
    printf("Elementos na fila:\n");
    for (int i = 0; i < fila->tamanho; i++) {
        printf("%d ", fila->dados[i]);
    }
    printf("\n");
}

// Função para liberar a memória alocada para a fila
void liberarFila(Fila *fila) {
    free(fila->dados);
    free(fila);
}

int main() {
    Fila *fila = criarFila(2);

    // Inserindo elementos na fila
    for (int i = 0; i < 10; i++) {
        inserir(fila, i);
    }

    // Removendo e exibindo alguns elementos
    printf("Removido: %d\n", remover(fila));
    inserir(fila, 10);
    printf("Removido: %d\n", remover(fila));
    inserir(fila, 11);
    printf("Removido: %d\n", remover(fila));
    inserir(fila, 12);

    // Mostrando todos os elementos restantes na fila
    printf("======== Mostrar ========\n");
    mostrar(fila);

    // Liberando a memória alocada
    liberarFila(fila);

    return 0;
}
