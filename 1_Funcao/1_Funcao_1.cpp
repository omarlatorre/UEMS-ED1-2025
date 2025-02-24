#include <stdio.h>
#include <stdlib.h>
using namespace std;

int x;
void quadrado(){
    int z;
    z = x * x;
    printf("O quadrado do numero e = %d \n", z);
}

int main(){
    printf("Digite um numero \n");
    scanf("%d", &x);
    printf("O numero inserido e = %d\n", x);
    quadrado();
    return 0;
}
