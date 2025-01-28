#include <stdio.h>

// Função para imprimir os espaços e asteriscos
void printLine(int spaces, int stars) {
    for (int i = 0; i < spaces; i++) {
        printf(" ");
    }
    for (int i = 0; i < stars; i++) {
        printf("*");
    }
    printf("\n");
}

void printDiamond(int n) {
  

    int middle = n / 2;
    for (int i = 0; i <= middle; i++) {
        int spaces = middle - i;
        int stars = 2 * i + 1;
        printLine(spaces, stars);
    }
    for (int i = middle - 1; i >= 0; i--) {
        int spaces = middle - i;
        int stars = 2 * i + 1;
        printLine(spaces, stars);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    printDiamond(n);
    return 0;
}
void printChar(char a, int n){

    for(int i=0; i<n; i++){
        printf("%c", a);
    }

}