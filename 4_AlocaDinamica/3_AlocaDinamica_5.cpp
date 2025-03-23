#include <stdio.h>
#include <stdlib.h>
using namespace std;

float ** aloca_matriz(int l, int c){
    float **mat;
    mat = (float **) malloc(l * sizeof(float *));
    for (int i = 0; i < l; i++)
    {
        mat[i] = (float *) malloc (c * sizeof(float));
    }
    return mat;
}

void desalocar_matriz(float **mat, int l, int c){
    for (int i = 0; i < l; i++)
    {
        free(mat[i]);
    }
    free(mat);
}

void preencher_matriz(float **mat, int l, int c){
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            mat[i][j] = i+j;
        }
    }
}

float ** soma_matriz(float **m1, float **m2, int l, int c){
    float **soma;
    soma = aloca_matriz(l, c);
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            soma[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return soma;
}

void imprime_matriz(float **mat, int l, int c){
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("  %f", mat[i][j]);
        }
        printf("\n");
    }
}

int main(){
    float **mat1, **mat2, **soma;
    mat1 = aloca_matriz(3,4);
    mat2 = aloca_matriz(3,4);
    soma = aloca_matriz(3,4);
    preencher_matriz(mat1, 3, 4);
    preencher_matriz(mat2, 3, 4);
    soma = soma_matriz(mat1, mat2, 3, 4);
    printf("A matriz 1 e seus elementos \n");
    imprime_matriz(mat1, 3, 4);
    printf("A matriz 2 e seus elementos \n");
    imprime_matriz(mat2, 3, 4);
    printf("A matriz soma e seus elementos \n");
    imprime_matriz(soma, 3, 4);
    desalocar_matriz(mat1, 3, 4);
    desalocar_matriz(mat2, 3, 4);
    desalocar_matriz(soma, 3, 4);
    return 0;
}