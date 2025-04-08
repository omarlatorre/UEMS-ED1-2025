/* Fila Sequencial 
*  o inicio da fila eh a posicao 0
*  o fim da fila eh a posicao ultimo
*/
#include <iostream>
using namespace std;

const int MAXFILA = 10;
const int ERROFILACHEIA = -1;
const int ERROFILAVAZIA = -2;

struct Fila{
    int dados[MAXFILA];
    int ultimo;
};

Fila aFila;

void inicializarFila(){
    aFila.ultimo = -1;
}

bool filaCheia(){
    if (aFila.ultimo == MAXFILA-1){
        return true;
    }
    else{
        return false;
    }
}

bool filaVazia(){
    if (aFila.ultimo == -1){
        return true;
    }
    else{
        return false;
    }
}

int enfileirar(int dado){
    if (filaCheia()){
        return ERROFILACHEIA;
    }
    else{
        aFila.ultimo += 1;
        aFila.dados[aFila.ultimo] = dado;
        return aFila.ultimo;
    }
}

int desenfileirar(){
    if (filaVazia()){
        return ERROFILAVAZIA;
    }
    else{
        /* inicio da fila na possição zero */
        for (int i = 0; i < aFila.ultimo; i++){
            aFila.dados[i] = aFila.dados[i+1];
        }
        aFila.ultimo -= 1;
        return aFila.ultimo;
    }
}

void limparDados(){
    int tamanho = aFila.ultimo;
    for (int i = tamanho; i > -1; i--){
        desenfileirar();
    }
}

void printDados(){
    for (int i = 0; i < aFila.ultimo + 1; i++){
        cout << i+1 << " --> "<< aFila.dados[i] << "\n";
    }
}

int menu(){
    int opcao;
    cout << "1. Enfileirar " << "\n";
    cout << "2. Desenfileirar " << "\n";
    cout << "3. Limpar " << "\n";
    cout << "4. Mostrar Fila " << "\n";
    cout << "5. Sair " << "\n";
    cout << "Insira opcao [1-5]  ";
    cin >> opcao;
    return opcao;
}

int main(){
    inicializarFila();
    int flag = 1, opcao, dado;
    while (flag){
        opcao = menu();
        switch (opcao){
        case 1:
            cout << "Insira um dado na Fila ";
            cin >> dado;
            enfileirar(dado); break;
        case 2: 
            cout << "Desenfileirando um dado na Fila " << "\n";
            desenfileirar(); break;
        case 3:
            cout << "Removendo todos os dados da Fila " << "\n";
            limparDados(); break;     
        case 4:
            cout << "Mostrando todos os dados da Fila" << "\n";
            printDados(); break;    
        case 5:
            cout << "Saindo do menu " << "\n";
            flag = 0;       
        default:
            break;
        }
    }
    return 0;
}