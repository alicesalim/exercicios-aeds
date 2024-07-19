#include <stdio.h>
#include <string.h>

#define MAX 100

void toLowerCase(char []);

int main() {
    int N, count = 0;
    char target[MAX], str[MAX];
    scanf("%d", &N);
    scanf("%s", target);

    toLowerCase(target);

    for(int i = 0; i < N; i++) {
        scanf(" %[^\n]", str);

        toLowerCase(str);

        if(strstr(str, target) != NULL) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
void toLowerCase(char str[]) {
    for(int i = 0; str[i]; i++){
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}