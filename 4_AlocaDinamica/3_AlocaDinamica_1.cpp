#include<stdio.h>
#include<stdlib.h>

using namespace std;

void ler_vetor(int size, int *v){
    for (int i = 0; i < size; i++)
    {
        printf("Insere o %d elemento = \n", i+1);
        scanf("%d", &v[i]);
    }
}

void imprime_vetor(int size, int *v){
    for (int i = 0; i < size; i++)
    {
        printf("vet[%d] = %d \n", i, v[i]);
    }
}

int main(){
    /* Inicializando o vetor e alocando dinamicamente */
    int n = 10;
    int *vet = (int *) malloc(n*sizeof(int));
    ler_vetor(n, vet);
    imprime_vetor(n, vet);
    /* removendo o espaço alocado dinamicamente */
    free(vet);
    return 0;
}