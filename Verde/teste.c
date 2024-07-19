1	#include <stdio.h>
2	#include <stdlib.h>
3	#define N 6
4	
5	void entradavetor(int vet[]);
6	void somavetor (int v[], int*);
7	void imprimevetor(int v[]);
8	
9	int main(){
10	  int vet[N];
11	  int soma=0;
12	  entradavetor(vet);
13	  somavetor(vet, &soma);
14	  printf("a soma dos valores 'é igual %d",soma);
15	  imprimevetor(vet);
16	  return 0;
17	}
18	
19	void entradavetor (int v[]){
20	  int i;
21	  for(i=0;i<N;i++){
22	    v[i] = rand()%10;
23	  }
24	}
25	
26	void somavetor(int v[], int* s){
27	  int i;
28	  for(i=0;i<N;i++){
29	    *s=*s+v[i];
30	  }
31	}
32	
33	void imprimevetor(int v[]){
34	  int i;
35	  printf("os valores do vetor são: ");
36	  for(i=0;i<N;i++){
37	    printf("%d | ", v[i]);
38	  }
39	}