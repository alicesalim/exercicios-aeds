#include <stdio.h>

int main(){

/*declarando os valores*/    
    int a, b, c;

/*recebendo os valores*/    
    printf("lado a: ");
    scanf("%d", &a);
    printf("lado b: ");
    scanf("%d", &b);
    printf("lado c: ");
    scanf("%d", &c);

/*testando se  a soma de dois lados é maior que o outro*/
    if((a+b>c)&&(b+c>a)&&(a+c>b)){
        printf("Formam um triângulo \n");

/*testando o tipo de triângulo*/        
        if ((a=!b)&&(b=!c)&&(a=!c)){
            printf("ESCALENO");
        }else if((a==b)&&(b==c)&&(a==c)){
            printf("EQUILATERO");
        }else{
            printf("ISOSCELES");
        }
    }else{
    printf("Não formam um triângulo");
    }

    return 0;
}    
