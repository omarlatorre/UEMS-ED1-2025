/* Lista Simplesmente Encadeada e Ordenada
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
		cout<<"1- Inserir na Lista\n";
		cout<<"2- Consultar toda a Lista\n";
		cout<<"3- Remover da Lista\n";
		cout<<"4- Esvaziar a Lista\n";
		cout<<"5- Sair\n";
		cout<<"Digite sua opcao ";
		cin>>op;
		if(op<1 || op>5){
			cout<<"Opcao invalida";
		}
		if(op == 1){
			cout<<"Digite numero a ser inserido na Lista ";
			LISTA *novo = new LISTA();
			cin>>novo->num;
			if(inicio == NULL){
				inicio = novo;
				fim = novo;
				fim->prox = NULL;
			}
			else{
				anterior = NULL;
				aux = inicio;
				while(aux != NULL && novo->num > aux->num){
					anterior = aux;
					aux = aux->prox;	
				}
				if(anterior == NULL){
					novo->prox = inicio;
					inicio = novo;
				}
				else if(aux == NULL){
					fim->prox = novo;
					fim = novo;
					fim->prox = NULL;
				}
				else{
					anterior->prox = novo;
					novo->prox = aux;
				}
			}
			cout<<"numero inserido no inicio da Lista"; 
		}
		if(op == 2){
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
		if(op == 3){
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
		if(op == 4){
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
	}while(op != 5);
	return 1;
}