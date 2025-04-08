#include <iostream>
using namespace std;

struct Fila{
    int *dados;
    int ini, fim, nelem, size;
};

Fila aFila;

void inicializarFila(int size){
    aFila.size = size;
    aFila.dados = new int[size];
    aFila.fim = -1;
    aFila.ini = aFila.nelem = 0;
}

bool filaCheia(){
    return(aFila.nelem == aFila.size);
}

bool filaVazia(){
    return(aFila.nelem == 0);
}

void enfileirar(int dado){
    if (aFila.nelem == aFila.size)
			printf("Fila cheia\n");
    aFila.fim++;
    if (aFila.fim >= aFila.size) 
        aFila.fim = 0;
    aFila.dados[aFila.fim] = dado;
    aFila.nelem++;
}

int desenfileirar(){
    if (aFila.nelem == 0)
		printf("Fila vazia");
    int ret = aFila.dados[aFila.ini];
    aFila.ini++;
    if (aFila.ini >= aFila.size) aFila.ini = 0;
    aFila.nelem--;
    return(ret);
}

void limparDados(){
    int tamanho = aFila.nelem;
    for (int i = tamanho; i > -1; i--){
        desenfileirar();
    }
}

void printDados(){
    int i = aFila.ini;
    while(i != aFila.fim+1){
        cout << " " << aFila.dados[i];
        i = i % aFila.size + 1;
    }
    cout << "\n";
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
    int size = 10;
    inicializarFila(size);
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