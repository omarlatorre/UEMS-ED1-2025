/* Lista Simplesmente Encadeada e Nao Ordenada 
*/
#include <iostream>
#include <conio.h>

using namespace std;

int main(){
	struct LISTA{
		int num;
		LISTA *prox;
	};
	LISTA *inicio = NULL;
	LISTA *fim = NULL;
	LISTA *aux;
	LISTA *anterior;
	int op,  numero, achou;
	do{
		cout<<"\nMENU DE OPCOES\n";
		cout<<"1- Inserir no inicio da Lista\n";
		cout<<"2- Inserir no fim da Lista\n";
		cout<<"3- Consultar toda a Lista\n";
		cout<<"4- Remover da Lista\n";
		cout<<"5- Esvaziar a Lista\n";
		cout<<"6- Sair\n";
		cout<<"Digite sua opcao ";
		cin>>op;
		if(op<1 || op>6){
			cout<<"Opcao invalida";
		}
		if(op == 1){
			cout<<"Digite numero a ser inserido no inicio da Lista ";
			LISTA *novo = new LISTA();
			cin>>novo->num;
			if(inicio == NULL){
				inicio = novo;
				fim = novo;
				fim->prox = NULL;
			}
			else{
				novo->prox = inicio;
				inicio = novo;
			}
			cout<<"numero inserido no inicio da Lista"; 
		}
		if(op == 2){
			cout<<"Digite o numero a ser inserido no fim da Lista ";
			LISTA *novo = new LISTA();
			cin>>novo->num;
			if(inicio == NULL){
				inicio = novo;
				fim = novo;
				fim->prox = NULL;
			} 
			else{
				fim->prox = novo;
				fim = novo;
				fim->prox = NULL;
			}
			cout<<"Numero inserido no fim da Lista";
		}
		if(op == 3){
			if(inicio == NULL){
				cout<<"Lista vazia";
			}
			else{
				cout<<"Consultando toda a Lista";
				aux = inicio;
				while(aux != NULL){
					cout<<aux->num<<" ";
					aux = aux->prox;
				}
			}
		}
		if(op == 4){
			if(inicio == NULL){
				cout<<"Lista vazia";
			}
			else{
				cout<<"Digite o numero a ser removido ";
				cin>>numero;
				aux = inicio;
				anterior = NULL;
				achou = 0;
				while(aux != NULL){
					if(aux->num == numero){
						achou = achou + 1;
						if(aux == inicio){
							inicio = aux->prox;
							delete(aux);
							aux = inicio;
						}
						else if(aux == fim){
							anterior->prox = NULL;
							fim = anterior;
							delete(aux);
							aux = NULL;
						}
						else{
							anterior->prox = aux->prox;
							delete(aux);
							aux = anterior->prox;
						}
					}
					else{
						anterior = aux;
						aux = aux->prox;
					}
				}
				if(achou == 0)
					cout<<"Numero nao encontrado";
				else if (achou == 1)
					cout<<"Numero removido uma vez";
				else
					cout<<"Numero removido "<<achou<<" vezes";
			}
		}
		if(op == 5){
			if(inicio == NULL){
				cout<<"Lista vazia";
			}
			else{
				aux = inicio;
				while(aux != NULL){
					inicio = inicio->prox;
					delete(aux);
					aux = inicio;
				}
				cout<<"Lista esvaziada";
			}
		}
	}while(op != 6);
	return 1;
}