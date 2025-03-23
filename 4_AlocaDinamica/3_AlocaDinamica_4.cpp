/*Exemplo de alocação dinamica da estrutura pessoa */
#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct
{
    char nome[100];
    int idade;
} pessoa ;

int main(){
    // alocando uma estrutura
    pessoa *p = (pessoa *) malloc(sizeof(pessoa));
    if (p)
    {
        p->idade = 3;
        printf("%d\n", p->idade);
        free(p);
    }
    return 0;
}
