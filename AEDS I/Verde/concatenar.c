#include <stdio.h>

int main(){

    //declarando m e n
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);

    //declarando vetores
    int a[m], b[n], c[m+n];

    //preenchendo a
    for(int i=0; i<m; i++){
        scanf("%d", &a[i]);
    }

    //preenchendo b
    for(int i=0; i<n; i++){
        scanf("%d", &b[i]);
    }

    //preenchendo c
    for(int i=0; i<m; i++){
        c[i]=a[i];
    }
    for(int i=0; i<n; i++){
        c[m+i]=b[i];
    }

    //saída

    for(int i=0; i<m; i++){
        printf("%d ", a[i]);
    }

    printf("\n");
    for(int i=0; i<n; i++){
        printf("%d ", b[i]);
    }

    printf("\n");
    for(int i=0; i<m+n; i++){
        printf("%d ", c[i]);
    }

    

}