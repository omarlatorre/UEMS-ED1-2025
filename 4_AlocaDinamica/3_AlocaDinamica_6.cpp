/* Exemplo: alocação dinamica de um vetor de registros de alunos */
#include <stdio.h>
#include <stdlib.h>

struct aluno{
    int matricula;
    char nome[40];
    int ano_nasc;
};
typedef struct aluno aluno;

void ler_vetor(aluno *vet_alunos, int n){
    /*armazeando os n registros no espaço alocado*/
    for(int i = 0 ; i < n; i++){
        printf("Numero de matricula: ");
        scanf("%d", &vet_alunos[i].matricula);
        printf("Nome: ");
        scanf(" %[^\n]", vet_alunos[i].nome);
        printf("Ano de nascimento: ");
        scanf("%d", &vet_alunos[i].ano_nasc);
        printf("\n\n");
    }
}

void imprime_vetor(aluno *vet_alunos, int n){
    /*mostrando os n registros armazenados*/
    for(int i = 0 ; i < n; i++){
        printf("Numero de matricula %d \n", vet_alunos[i].matricula);
        printf("Nome: %s \n" , vet_alunos[i].nome);
        printf("Ano de nascimento: %d\n\n" , vet_alunos[i].ano_nasc);
    }
}

int main(){
    int n, i;
    aluno *ptr;
    printf("Entre com o numero de registros a serem alocados: ");
    scanf("%d", &n);
    /*alocando espaço para n registros*/
    ptr = (aluno*)malloc(n * sizeof(aluno));
    ler_vetor(ptr, n);
    imprime_vetor(ptr, n);
    /*desalocando o espaço utilizado anteriormente*/
    free(ptr);
    return 0;
}