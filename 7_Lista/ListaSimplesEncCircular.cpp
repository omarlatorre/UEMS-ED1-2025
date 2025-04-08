/* Lista Simplesmente Encadeada Circular
*/
#include <iostream>
#include <conio.h>

using namespace std;

int main(){
	// Definindo o registro que representara
	// cada elemento da lista
	struct Lista{
		int num;
		Lista *prox;
	};
	// a lista esta vazia, logo
	// o ponteiro inicio tem o valor null
	// o ponteiro inicio conterá o endereço
	// do primeiro elemento da lista
	Lista *inicio = NULL;
	Lista *fim = NULL;
	Lista *aux;
	Lista *anterior;
	int op, numero, achou;
	do{
		cout << "\nMENU DE OPCOES\n";
		cout << "1 - Inserir no inicio da lista\n";
		cout << "2 - Inserir no fim da lista\n";
		cout << "3 - Consultar toda a lista\n";
		cout << "4 - Remover da lista\n";
		cout << "5 - Esvaziar a lista\n";
		cout << "6 - Sair\n";
		cout << "Digite sua opcao ";
		cin >> op;
		if (op < 1 || op > 6)
			cout << "Opcao invalida";
		if (op == 1){
			cout<<"Digite o numero a ser inserido no inicio da lista ";
			Lista *novo = new Lista();
			cin>>novo->num;
			if(inicio == NULL){
				inicio = novo;
				fim = novo;
				fim->prox = inicio;
			}
			else{
				novo->prox = inicio;
				inicio = novo;
				fim->prox = inicio;
			}
			cout<<"Numero inserido no inicio da lista";
		}
		if(op == 2){
			cout<<"Digite o numero a ser inserido no fim da lista ";
			Lista *novo = new Lista();
			cin>>novo->num;
			if(inicio == NULL){
				inicio = novo;
				fim = novo;
				fim->prox = inicio;
			}
			else{
				fim->prox = novo;
				fim = novo;
				fim->prox = inicio;
			}
			cout<<"Numero inserido no fim da lista";
		}
		if(op == 3){
			if(inicio == NULL){
				cout<<"Lista vazia";
			}
			else{
				cout<<"Consultando toda a lista\n";
				aux = inicio;
				do{
					cout<<aux->num<<" ";
					aux = aux->prox;
				}
				while(aux!=inicio);
			}
		}
		if(op == 4){
			if(inicio == NULL){
				cout<<"lista vazia";
			}
			else{
				cout<<"Digite o elemento a ser removido ";	
				cin>>numero;
				aux = inicio;
				anterior = NULL;
				achou = 0;
				int quantidade = 0;
				aux = inicio;
				do{
					quantidade = quantidade +1;
					aux = aux->prox;
				}
				while(aux != inicio);
				int elemento = 1;
				do{
					if(inicio == fim && inicio->num == numero){
						delete(inicio);
						inicio = NULL;
						achou = achou +1;
					}
					else{
						if(aux->num == numero){
							achou = achou +1;
							if(aux == inicio){
								inicio = aux->prox;
								fim->prox = inicio;
								delete(aux);
								aux = inicio;
							}
							else if (aux == fim){
								fim = anterior;
								fim->prox = inicio;
								delete(aux);
								aux = NULL;
							}
							else{
								anterior->prox=aux->prox;
								delete(aux);
								aux = anterior->prox;
							}	
						}
						else{
							anterior = aux;
							aux = aux->prox;
						}
					}
					elemento = elemento + 1;
				}
				while(elemento <= quantidade);
				if(achou == 0)
					cout<<"Numero não enontrado";
				else if(achou == 1)
					cout<<"numero removido uma vez";
				else
					cout<<"numero removido "<<achou<<"vezes";
			}
		}
		if(op == 5){
			if(inicio == NULL){
				cout<<"lista vazia\n";
			}
			else{
				aux = inicio;
 				do{
					inicio = inicio->prox;
					delete(aux);
					aux = inicio;
				}
				while(aux != fim);
				delete(fim);
				inicio = NULL;
				cout<<"Lista vazia\n";
			}
		}
	} while(op!=6);
	return 0;
}