/* Lista Duplamente Encadeada e Ordenada
*/
#include <iostream>
#include <conio.h>

using namespace std;

int main(){
	struct LISTA{
		int num;
		LISTA *prox;
		LISTA *ant;
	};
	LISTA *inicio = NULL;
	LISTA *fim = NULL;
	LISTA *aux;
	int op, numero, achou;
	do{
		cout<<"\nMENU DE OPCOES\n";
		cout<<"1- Inserir na Lista\n";
		cout<<"2- Consultar a Lista do inicio ao fim\n";
		cout<<"3- Consultar a Lista do fim ao inicio\n";
		cout<<"4- Remover da Lista\n";
		cout<<"5- Esvaziar a Lista\n";
		cout<<"6- Sair\n";
		cout<<"Digite sua opcao ";
		cin>>op;
		if(op<1 || op>6){
			cout<<"Opcao invalida";
		}
		if(op == 1){
			cout<<"Digite numero a ser inserido na Lista ";
			LISTA *novo = new LISTA();
			cin>>novo->num;
			if(inicio == NULL){
				novo->prox = NULL;
				novo->ant = NULL;
				inicio = novo;
				fim = novo;
			}
			else{
				aux = inicio;
				while(aux != NULL && novo->num > aux->num){
					aux = aux->prox;
				}
				if(aux == inicio){
					novo->prox = inicio;
					novo->ant = NULL;
					inicio->ant = novo;
					inicio = novo;
				}
				else if (aux == NULL){
					fim->prox = novo;
					novo->ant = fim;
					fim = novo;
					fim->prox = NULL;
				}
				else{
					novo->prox = aux;
					aux->ant->prox = novo;
					novo->ant = aux->ant;
					aux->ant = novo;
				}
			}
			cout<<"numero inserido no inicio da Lista"; 
		}
		if(op == 2){
			if(inicio == NULL){
				cout<<"Lista vazia";
			}
			else{
				cout<<"Consultando a Lista do inicio ao fim";
				aux = inicio;
				while(aux != NULL){
					cout<<aux->num<<" ";
					aux = aux->prox;
				}
			}
		}
		if(op == 3){
			if(inicio == NULL){
				cout<<"Lista vazia";
			}
			else{
				cout<<"Consultando a Lista do fim ao inicio";
				aux = fim;
				while(aux != NULL){
					cout<<aux->num<<" ";
					aux = aux->ant;
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
				achou = 0;
				while(aux != NULL){
					if(aux->num == numero){
						achou = achou + 1;
						if(aux == inicio){
							inicio = aux->prox;
							if(inicio != NULL)
								inicio->ant = NULL;
							delete(aux);
							aux = inicio;
						}
						else if(aux == fim){
							fim = fim->ant;
							fim->prox = NULL;
							delete(aux);
							aux = NULL;
						}
						else{
							aux->ant->prox = aux->prox;
							aux->prox->ant = aux->ant;
							LISTA *aux2;
							aux2 = aux->prox;
							delete(aux);
							aux = aux2;
						}
					}
					else{
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