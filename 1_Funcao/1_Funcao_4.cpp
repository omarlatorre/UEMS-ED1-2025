#include <stdio.h>
#include <stdlib.h>
using namespace std;

int x, y;
int quadrado(int w){
    int z;
    z = w * w;
    return z;
}

int main(){
    printf("Digite um numero \n");
    scanf("%d", &x);
    printf("O numero inserido e = %d\n", x);
    y = quadrado(x);
    printf("O quadrado do numero e = %d \n", y);
    return 0;
}
