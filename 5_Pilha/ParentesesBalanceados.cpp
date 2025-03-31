#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <climits>
#include <cstring>
#define MAX 100


// Uma estrutura que representa uma pilha
struct Pilha { 
    int topo; 
    int maxPilha; 
    char* dado; 
}; 

struct Pilha* inicializaPilha(int max) 
{ 
    struct Pilha* pilha = (struct Pilha*)malloc(sizeof(struct Pilha)); 
    pilha->maxPilha = max; 
    pilha->topo = -1; 
    pilha->dado = (char*)malloc(pilha->maxPilha * sizeof(char));
    // aqui tem-se alocacao dinamica de memoria
    return pilha; 
}

// pilhaCheia: esta funcao determina se a pilha esta cheia ou nao
// retornara true se esta cheia senao false
// Pilha esta cheia quando o topo e igual ao ultimo indice
int pilhaCheia(struct Pilha* pilha) 
{ 
    if(pilha->topo == pilha->maxPilha - 1){
        printf("A pilha alcancou seu maximo tamanho\n");
    }
    // Lembrando: os indices do vetor comecam em 0 e termina em maxPilha de um em um 
    return pilha->topo == pilha->maxPilha - 1; 
}

// Por definicao a pilha e vazia quando o topo e igual a -1
// retornara true se o topo e -1
int pilhaVazia(struct Pilha* pilha) 
{ 
    return pilha->topo == -1; 
}

// A funcao empilha, insere um valor na pilha e acrescenta 1 ao topo da pilha
void empilha(struct Pilha* pilha, char item) 
{ 
    if (pilhaCheia(pilha)) 
        return; 
    pilha->dado[++pilha->topo] = item; 
}

// Funcao que elimina um item da pilha, decrementa topo em 1
void desempilha(struct Pilha* pilha) 
{ 
    if (pilhaVazia(pilha)) 
        return; 
    
    pilha->dado[pilha->topo--]; 
} 

// Funcao retornara o item cujo indice e o topo da pilha sem remove-lo
int topo(struct Pilha* pilha) 
{ 
    if (pilhaVazia(pilha)) 
        return INT_MIN; 
    return pilha->dado[pilha->topo]; 
} 

bool verificaPar(char val1,char val2){
    return (( val1=='(' && val2==')' )||( val1=='[' && val2==']' )||( val1=='{' && val2=='}' ));
}

bool verificaBalanceamento(struct Pilha* pilha, char expr[], int len){
      
    for (int i = 0; i < len; i++)  
    { 
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')  
        {  
          empilha(pilha, expr[i]); 
        } 
        else
        {
            // exp = {{}}}
            // observe que {{}} sera emparelhado com seu par, isto e, a pilha "Vazia"
            // porem uma chave extra de fechamento como '}' nunca sera emparelhado
            // desta forma se fara o retrocesso 
        if (pilhaVazia(pilha)) 
            return false;
        else if(verificaPar(topo(pilha),expr[i]))
        {
            desempilha(pilha);
            continue;
        }
        // o fluxo do programa chegara a este ponto se a pilha nao estiver vazia
        // pois um par nao foi achado seu parantesis de fechadura
        //Exemplo : {{}}(]
        return false;
        }
    }    
    return pilhaVazia(pilha) ? true : false;
}
int main() {
  char exp[MAX] = "({})[]";

  int len = strlen(exp);
  struct Pilha* pilha = inicializaPilha(len); 
  verificaBalanceamento(pilha, exp, len)?printf("Balanceado"): printf("Nao balanceado"); 

  return 0;
}