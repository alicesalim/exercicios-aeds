
/*import java.util.Scanner;

class Deus {
    String nome;
    int poder;
    int matou;
    int morreu;

    public Deus(String nome, int poder, int matou, int morreu) {
        this.nome = nome;
        this.poder = poder;
        this.matou = matou;
        this.morreu = morreu;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Ler o número de deuses
        int n = scanner.nextInt();
        scanner.nextLine(); // Consumir a quebra de linha

        // Criar um array de deuses
        Deus[] deuses = new Deus[n];

        // Ler os dados dos deuses
        for (int i = 0; i < n; i++) {
            String nome = scanner.next();
            int poder = scanner.nextInt();
            int matou = scanner.nextInt();
            int morreu = scanner.nextInt();
            scanner.nextLine(); // Consumir a quebra de linha

            deuses[i] = new Deus(nome, poder, matou, morreu);
        }

        // Determinar o ganhador
        Deus ganhador = deuses[0];

        for (int i = 1; i < n; i++) {
            Deus atual = deuses[i];

            if (atual.poder > ganhador.poder) {
                ganhador = atual;
            } else if (atual.poder == ganhador.poder) {
                if (atual.matou > ganhador.matou) {
                    ganhador = atual;
                } else if (atual.matou == ganhador.matou) {
                    if (atual.morreu < ganhador.morreu) {
                        ganhador = atual;
                    } else if (atual.morreu == ganhador.morreu) {
                        if (atual.nome.compareTo(ganhador.nome) < 0) {
                            ganhador = atual;
                        }
                    }
                }
            }
        }

        // Exibir o nome do ganhador
        System.out.println(ganhador.nome);

        scanner.close();
    }
}
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
