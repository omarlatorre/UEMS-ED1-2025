/* Arvore binária
*/
#include <iostream>
#include <conio.h>

// Definindo o registro que representará
// Cada elemento da árvore binária

using namespace std;

struct ARVORE{
	int num;
	ARVORE *esq, *dir;
};

// Definindo o registro que representará
// cada elemento da árvore binária na pilha

struct PILHA{
	ARVORE *num;
	PILHA *prox;
};

int main(){
	// a árvore está vazia, logo
	// o ponteiro raiz tem o valor null
	ARVORE *raiz = NULL;
	// o ponteiro aux é um ponteiro auxiliar
	ARVORE *aux;
	// o ponteiro aux1 é um ponteiro auxiliar
	ARVORE *aux1;
	// o ponteiro novo é um ponteiro auxiliar
	ARVORE *novo;
	// o ponteiro anterior é um ponteiro auxiliar
	ARVORE *anterior;
	// o ponteiro topo representa a topo da pilha
    PILHA *topo;
	// o ponteiro aux_pilha é um ponteiro auxiliar da pilha
	PILHA *aux_pilha;
	// apresentando o menu de opções
	int op,  numero, achou;
	do{
		cout<<"\nMENU DE OPCOES\n";
		cout<<"1- Inserir na arvore\n";
		cout<<"2- Consultar um no da arvore\n";
		cout<<"3- Consultar toda a arvore em ordem\n";
		cout<<"4- Consultar toda a arvore em pre-ordem\n";
		cout<<"5- Consultar toda a arvore em pos-ordem\n";
		cout<<"6- Excluir um no da arvore\n";
		cout<<"7- Esvaziar a arvore\n";
		cout<<"8- Sair\n";
		cout<<"Digite sua opcao ";
		cin>>op;
		if(op<1 || op>8){
			cout<<"Opcao invalida";
		}
		if(op == 1){
			cout << "Digite o numero a ser inserido na arvore";
			novo = new ARVORE();
			cin >> novo->num;
			novo->dir = NULL;
			novo->esq = NULL;
			if(raiz == NULL){
				raiz = novo;
			}
			else{
				aux = raiz;
				achou = 0;
				while (achou == 0){
					if(novo->num < aux->num){
						if(aux->esq == NULL){
							aux->esq = novo;
							achou = 1;
						}
						else aux = aux->esq;
					} else if (novo->num >= aux->num){
						if(aux->dir == NULL){
							aux->dir = novo;
							achou = 1;
						}	
						else aux = aux->dir;
					}
				}
			}
			cout<<"numero inserido no inicio da arvore"; 
		}
		if(op == 2){
			if(raiz == NULL){
				cout<<"Arvore vazia";
			}
			else{
				cout<<"Digite o elemento a ser consultado";
				cin >> numero;
				achou = 0;
				aux = raiz;
				while(aux != NULL && achou == 0){
					if(aux->num == numero){
						cout << "Numero encontrado na arvore";
						achou = 1;
					} else if(numero < aux->num){
						aux = aux->esq;
					}
					else aux = aux->dir;
				}
				if(achou == 0)
					cout << "Numero nao encontrado na arvore";
			}
		}
		if(op == 3){
			if(raiz == NULL){
				cout<<"Arvore vazia";
			}
			else{
				cout<<"Listando todos os elementos da arvore em ordem";
				aux = raiz;
				topo = NULL;
				do{
					while(aux != NULL){
						aux_pilha = new PILHA();
						aux_pilha->num = aux;
						aux_pilha->prox = topo;
						topo = aux_pilha;
						aux = aux->esq;
					}
					if(topo != NULL){
						aux_pilha = topo;
						cout << aux_pilha->num->num << " ";
						aux = topo->num->dir;
						topo = topo->prox;
					}
				}while(topo != NULL || aux != NULL);
			}
		}
		if(op == 4){
			if(raiz == NULL){
				cout<<"Arvore vazia";
			}
			else{
				cout<<"Listando todos os elementos da arvore em pre-ordem";
				aux = raiz;
				topo = NULL;
				do{
					while(aux != NULL){
						aux_pilha = new PILHA();
						cout << aux_pilha->num->num << " ";
						aux_pilha->num = aux;
						aux_pilha->prox = topo;
						topo = aux_pilha;
						aux = aux->esq;
					}
					if(topo != NULL){
						aux_pilha = topo;
						topo = topo->prox;
						aux = topo->num->dir;
					}
				}while(topo != NULL || aux != NULL);
			}
		}
		if(op == 5){
			if(raiz == NULL){
				cout<<"Arvore vazia";
			}
			else{
				cout<<"Listando todos os elementos da arvore em pos-ordem";
				aux = raiz;
				topo = NULL;
				do{
					do{
						while(aux != NULL){
							aux_pilha = new PILHA();
							aux_pilha->num = aux;
							aux_pilha->prox = topo;
							topo = aux_pilha;
							aux = aux->esq;
						}
						if(topo->num->dir != NULL){
							aux = topo->num->dir;
						}
					}while(aux != NULL);
					if(topo != NULL){
						cout << topo->num->num << " ";
						if(topo->prox != NULL){
							if(topo->prox->num->dir != NULL && topo->prox->num->dir != topo->num){
								aux = topo->prox->num->dir;
								topo = topo->prox;
							}else{
								while(topo->prox != NULL && topo->prox->num->dir == topo->num){
									topo = topo->prox;
									cout << topo->num->num <<" ";
								}
								topo = topo->prox;
								if(topo != NULL)
									aux = topo->num->dir;
								else
									aux = NULL;
							}
						}else{
							topo = topo->prox;
							aux = NULL;
						}
					}
				}while(topo != NULL || aux != NULL);
			}
		}
		if(op == 6){
			if(raiz == NULL)
				cout << "Arvore vazia";
			else{
				cout << "Digite o numero que deseja excluir";
				cin >> numero;
				aux = raiz;
				achou = 0;
				while(achou == 0 && aux != NULL){
					if(aux->num == numero)
						achou = 1;
					else if(aux->num > numero)
						aux = aux->esq;
					else aux = aux->dir;
				}
				if(achou == 0)
					cout << "Numero nao encontrado";
				else{
					if(aux != raiz){
						anterior = raiz;
						while(anterior->dir != aux && anterior->esq != aux){
							if(anterior->num > numero)
								anterior = anterior->esq;
							else anterior = anterior->dir;
						} 
						if(aux->dir == NULL && aux->esq == NULL){
							if(anterior->dir == aux)
								anterior->dir = NULL;
							else anterior->esq = NULL;
							delete(aux);
						}else{
							if(aux->dir != NULL && aux->esq == NULL){
								if(anterior->esq == aux)
									anterior->esq = aux->dir;
								else anterior->dir = aux->dir;
								delete(aux);
							} else if(aux->esq != NULL && aux->dir == NULL){
								if(anterior->esq == aux)
									anterior->esq = aux->esq;
								else anterior->dir = aux->esq;
								delete(aux);
							} else if(aux->esq != NULL && aux->dir != NULL){
								if(anterior->dir == aux){
									anterior->dir = aux->dir;
									aux1= aux->esq;
								}else{
									anterior->esq = aux->dir;
									aux1 = aux->esq;
								}
								delete(aux);
								aux = anterior;
								while(aux != NULL){
									if(aux->num < aux1->num){
										if(aux->dir == NULL){
											aux->dir = aux1;
											aux = NULL;
										}else aux = aux->dir;
									}else if(aux->num > aux1->num){
										if(aux->esq == NULL){
											aux->esq = aux1;
											aux = NULL;
										} else aux = aux->esq;
									}
								}
							}
						}
					} else{
						if(aux->dir == NULL && aux->esq == NULL){
							delete aux;
							raiz = NULL;
						}else{
							if(aux->dir != NULL && aux->esq == NULL){
								raiz = aux->dir;
								delete aux;
							}else if(aux->esq != NULL && aux->dir == NULL){
								raiz = aux->esq;
								delete aux;
							} else if (aux->esq != NULL && aux->dir != NULL){
								raiz = aux->dir;
								aux1 = aux->esq;
								delete aux;
								aux = aux->dir;
								while(aux != NULL){
									if(aux->num < aux1->num){
										if(aux->dir == NULL){
											aux->dir = aux1;
											aux = NULL;
										} else aux = aux->dir;
									} else if (aux->num > aux1->num){
										if(aux->esq == NULL){
											aux->esq = aux1;
											aux = NULL;
										}
										else aux = aux->esq;
									}
								}
							}
						}	
					}
					cout << "Numero excluido da arvore";
				}
			}
		}
		if(op == 7){
			if(raiz == NULL)
				cout << "Arvore vazia";
			else{
				aux = raiz;
				topo = NULL;
				do{
					while(aux != NULL){
						aux_pilha = new PILHA();
						cout << aux->num << " ";
						aux_pilha->num = aux;
						aux_pilha->prox = topo;
						topo = aux_pilha;
						aux = aux->esq;
					}
					if(topo != NULL){
						aux_pilha = topo;
						topo = topo->prox;
						aux = aux_pilha->num->dir;
					}
				}while(topo != NULL || aux != NULL);
				aux_pilha = topo;
				while(aux_pilha != NULL){
					topo = topo->prox;
					delete(topo->num);
					delete(aux_pilha);
					aux_pilha = topo;
				}
				raiz = NULL;
				cout << "Arvore esvaziada";
			}
		}
	}while(op != 8);
	return 1;
}