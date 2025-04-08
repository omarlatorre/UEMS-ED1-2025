#include<iostream>
using namespace std;
struct FILA{
	int el;
	FILA *prox;
};

FILA *inicio = NULL;
FILA *fim = NULL;

int menu(){
    int op;
    cout<<"\nMENU DE OPCOES\n";
	cout<<"1- Inserir na fila\n";
	cout<<"2- Consultar toda a fila\n";
	cout<<"3- Remover da fila\n";
	cout<<"4- Esvaziar a fila\n";
	cout<<"5- Sair\n";
	cout<<"Escolha uma opcao ";
	cin>>op;
	return op;
}

void enfileirar(){
    cout<<"Digite o numero a ser inserido na fila";
	FILA *novo = new FILA();
	cin>>novo->el;
	novo->prox = NULL;
	if(inicio == NULL){
		inicio = novo;
		fim = novo;
	}
	else{
		fim->prox = novo;
		fim = novo;
	}
	cout<<"Numero inserido na fila";
}

void desenfileirar(){
    FILA *aux;
    if(inicio == NULL){
		cout<<"Fila vazia";
	}
	else{
		aux = inicio;
		cout<<"Numero "<<inicio->el<<" removido\n";
		inicio = inicio->prox;
		delete(aux);
	}
}

void printDados(){
    FILA *aux;
    if(inicio == NULL){
		cout<<"Fila vazia";
	}
	else{
		cout<<"Consultado toda a fila ";
		aux = inicio;
		while(aux != NULL){
			cout<< aux->el<<" ";
			aux = aux->prox;
		}
	}
}

void limparDados(){
    FILA *aux;
    if(inicio == NULL){
		cout<<"Fila vazia";
	}
	else{
		aux = inicio;
		while(aux != NULL){
			inicio = inicio->prox;
			delete(aux);
			aux = inicio;
		}
		cout<<"Fila esvaziada";
	}
}

int main(){
	int flag = 1, opcao;
	while(flag){
	    opcao = menu();
	    switch(opcao){
	        case 1: enfileirar(); break;
	        case 2: printDados(); break;
	        case 3: desenfileirar(); break;
	        case 4: limparDados(); break;
	        case 5: cout << "Saindo do menu \n";
	            flag = 0;
	        default:
	            break;
	    }
	}
	return 0;
}
