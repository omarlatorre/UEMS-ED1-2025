#include <iostream>
using namespace std;

struct PILHA{
	int num;
	PILHA *prox;
};
PILHA *topo = NULL;

void apilhar(){
    cout<<"Digite o numero a ser inserido na pilha";
	PILHA *novo = new PILHA();
	cin>>novo->num;
	novo->prox = topo;
	topo = novo;
	cout<<"Numero inserido na Pilha";
}

void desapilhar(){
    PILHA *aux;
    if(topo == NULL){
        cout<<"Pilha vazia";
	}
	else{
		aux = topo;
		cout<<"Numero "<<topo->num<<" removido";
		topo = topo->prox;
		delete(aux);
	}
}

void printDados(){
    PILHA *aux;
    if(topo == NULL){
		cout<<"Pilha vazia";
	}
	else{
		cout<<"Consultando toda a Pilha";
		aux = topo;
		while(aux != NULL){
			cout<<aux->num<<" ";
			aux = aux->prox;
		}
	}
}

void limparDados(){
    PILHA *aux;
    if(topo == NULL){
		cout<<"Pilha vazia";
	}
	else{
		aux = topo;
		while(aux != NULL){
			topo = topo->prox;
			delete(aux);
			aux = topo;
		}
		cout<<"Pilha esvaziada";
	}
}

int main(){
	PILHA *aux;
	int op;
	do{
		cout<<"\n MENU DE OPCOES\n";
		cout<<"\n1 - Inserir na Pilha";
		cout<<"\n2 - Consultar toda a Pilha";
		cout<<"\n3 - Remover a Pilha";
		cout<<"\n4 - Esvaziar a Pilha";
		cout<<"\n5 - Sair";
		cout<<"\nDigite sua opcao ";
		cin>>op;
		if(op < 1 || op > 5)
			cout<<"Opcao invalida";	
		if(op == 1){
		    apilhar();
		}
		if(op == 2){
		    printDados();
		}
		if(op == 3){
			desapilhar();
		}
		if(op == 4){
			limparDados();
		}
	}
	while(op != 5);
	return 0;
}