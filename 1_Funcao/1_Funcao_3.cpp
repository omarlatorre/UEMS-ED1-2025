#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;
string nome;
void le_nome(){
    printf("Insira um nome ");
    scanf("%s", nome);
}
void muda_nome(){
    string nome;
    printf("vamos mudar o nome ");
    scanf("%s", nome);
}

int main(){
    le_nome();
    printf("%s\n", nome);
    muda_nome();
    printf("%s\n", nome);
    return 0;
}