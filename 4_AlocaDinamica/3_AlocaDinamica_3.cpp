#include <stdio.h>
#include <stdlib.h>

using namespace std;

int ** inicializa_matriz(int fila, int col, int **mat){
    mat = (int **) calloc(fila, sizeof(int *));
    if (mat == NULL)
    {
        printf("Memoria insuficiente para armazenar \n");
        exit(1);
    }
    for (int i = 0; i < fila; i++)
    {
        mat[i] = (int *) calloc(col, sizeof(int));
        if (mat[i] == NULL)
        {
            printf("Memoria insuficiente para alocar");
            exit(1);
        }
        
    }
    return mat;
}

void desalocar_matriz(int fila, int col, int **mat){
    for (int i = 0; i < fila; i++)
    {
        free(mat[i]);
    }
    free(mat);
}

void somar_eltos(int fila, int col, int **mat){
    int soma = 0;
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < col; j++)
        {
            soma += mat[i][j];
            printf("mat[%d][%d] = %d\n", i+1,j+1, mat[i][j]);
        }
    }
    printf("A soma dos elementos da matriz = %d ", soma);
}

void preencher_eltos(int fila, int col, int **mat){
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mat[i][j] = i+j;
        }
    }
}

int main(){
    /*Inicialização da matriz*/
    int m = 3;
    int n = 4;
    int **mat;
    mat = inicializa_matriz(m,n,mat);
    preencher_eltos(m,n,mat);
    somar_eltos(m,n,mat);
    desalocar_matriz(m,n,mat);
}