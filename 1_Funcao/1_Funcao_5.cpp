#include <stdio.h>
#include <stdlib.h>
using namespace std;

int x;
float fatorial(int x){
    float fat = 1;
    for (int i = x; i >= 1; i--)
    {
        fat = fat * i;
    }
    return fat;
}

int main(){
    int n, p, C;
    printf("Digite o numero de elementos \n");
    scanf("%d", &n);
    printf("Digite o numero p tomados p a p \n");
    scanf("%d", &p);
    if (p >= 0 && n >= 0 && p <= n)
    {
        C = fatorial(n)/(fatorial(p) * fatorial(n-p));
    }
    printf("As combinações possiveis n em p = %d", C);
    return 0;
}
