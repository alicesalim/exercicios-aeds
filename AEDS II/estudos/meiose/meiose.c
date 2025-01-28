#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#define bool   short
#define true   1
#define false  0

//TIPO CELULA ===================================================================
typedef struct Celula {
	int elemento;        // Elemento inserido na celula.
	struct Celula* prox; // Aponta a celula prox.
} Celula;

Celula* novaCelula(int elemento) {
   Celula* nova = (Celula*) malloc(sizeof(Celula));
   nova->elemento = elemento;
   nova->prox = NULL;
   return nova;
}

//LISTA PROPRIAMENTE DITA =======================================================
Celula* primeiro;
Celula* ultimo;

//no cabeca
void start () {
   primeiro =novaCelula(-1);
   ultimo = primeiro;
}
void inserirFim(int x) {
   ultimo->prox = novaCelula(x);
   ultimo = ultimo->prox;
}

void mostrar() {
   printf("[ ");
   Celula* i;
   for (i = primeiro->prox; i != NULL; i = i->prox) {
      printf("%d ", i->elemento);
   }
   printf("] \n");
}
void meiose(){
    Celula *atual = primeiro->prox;
    while(atual !=NULL){
        Celula *nova = novaCelula(atual->elemento/2);
        
        Celula *novaCelula = (Celula *)malloc(1 * sizeof(Celula));// cria nova celula
        atual->elemento = atual->elemento/2;//celula recebe x/2
        //nova->elemento = atual->elemento;//nova celula recebe x/2
        nova->prox = atual->prox;
        atual->prox = nova;
        atual = nova->prox;//andar com ponteiro
    }
}

int main() {
   printf("=== LISTA DINAMICA SIMPLESMENTE ENCADEADA === \n\n");

   start();
   inserirFim(8);
   inserirFim(5);
   inserirFim(6);
   inserirFim(1);

   printf("Apos insercoes: ");
   mostrar();
    meiose();
   printf("Apos meiose : ");
   mostrar();
   return 0;
}