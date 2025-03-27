#include <iostream>
using namespace std;

const int MAXPILHA = 10;
const int ERROPILHACHEIA = -1;
const int ERROPILHAVAZIA = -2;

struct Pilha
{
    int dados[MAXPILHA];
    int topo;
};

Pilha aPilha;

void inicializaPilha(){
    aPilha.topo = -1;
}

bool pilhaCheia(){
    if (aPilha.topo == MAXPILHA-1){
        return true;
    }
    else{
        return false;
    }
}

bool pilhaVazia(){
    if (aPilha.topo == -1){
        return true;
    }
    else{
        return false;
    }
}

int empilha(int dado){
    if (pilhaCheia())
    {
        return ERROPILHACHEIA;
    }
    else{
        aPilha.topo = aPilha.topo + 1;
        aPilha.dados[aPilha.topo] = dado;
        return aPilha.topo;
    }
}

int desempilha(){
    if (pilhaVazia())
    {
        return ERROPILHAVAZIA;
    }
    else{
        aPilha.topo = aPilha.topo - 1;
        return aPilha.topo;
    }
}

int topo(){
    if (pilhaVazia()){
        cout << "ERRO: Pilha vazia ao acessar" << "\n";
        return ERROPILHAVAZIA;
    }
    else{
        return aPilha.dados[aPilha.topo];
    }
}

void limparDados(){
    int tamanho = aPilha.topo;
    for (int i = tamanho; i > -1; i--){
        desempilha();
    }
}

void printDados(){
    for (int i = 0; i < aPilha.topo+1; i++){
        cout << aPilha.dados[i] << "\n";
    }
}

int menu(){
    int opcao;
    cout << "1. Empilhar " << "\n";
    cout << "2. Desempilhar " << "\n";
    cout << "3. Limpar " << "\n";
    cout << "4. Mostrar Pilha " << "\n";
    cout << "5. Sair " << "\n";
    cout << "Insira opção [1-5]  ";
    cin >> opcao;
    return opcao;
}

int main(){
    inicializaPilha();
    int opcao, estado, dado, flag = 1;
    while (flag)
    {
        opcao = menu();
        switch (opcao)
        {
        case 1:
            cout << "Insira um dado a Pilha ";
            cin >> dado;
            estado = empilha(dado);
            break;
        case 2: 
            cout << "Desempilhando um dado na Pilha" << "\n";
            estado = desempilha();
            break;
        case 3:
            cout << "Removendo todos os dados da Pilha" << "\n";
            limparDados();
            break;
        case 4:
            cout << "Mostrando todos os dados da Pilha" << "\n";
            printDados();
            break;
        case 5:
            cout << "Saindo do menu " << "\n";
            flag = 0;
        default:
            break;
        }   
    }
    return 0;
}