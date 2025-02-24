#include <stdio.h>
#include <stdlib.h>
using namespace std;

int x;
int par(int w){
    if (w % 2 == 0)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int n, x, somapar = 0;
    printf("Digite o numero numeros a serem inseridos \n");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("Digite o %d numero ", i);
        scanf("%d", &x);
        somapar = somapar + par(x);
    }
    
    printf("O numero de elemetos pares e %d", somapar);
    return 0;
}
