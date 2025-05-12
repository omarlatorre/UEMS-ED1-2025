/* Arvore binária recursiva
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

ARVORE* inserir (ARVORE* aux, int num){
	if(aux == NULL){
		aux = new ARVORE();
		aux->num = num;
		aux->esq = NULL;
		aux->dir = NULL;
	}
	else if(num < aux->num)
		aux->esq = inserir(aux->esq, num);
	else	
		aux->dir = inserir(aux->dir, num);
	return aux;
}

unsigned short alt(ARVORE *x) {
	if (!x) return 0; // caso trivial
	// chamada recursiva para calcular a altura da subárvore esquerda
	unsigned short hesq = alt(x->esq);
	// chamada recursiva para calcular a altura da subárvore direita
	unsigned short hdir = alt(x->dir);
	// retorna a maior altura calculada + 1
	return(1 + (hesq>hdir? hesq : hdir) );
}

int consultar(ARVORE* aux, int num, int achou){
	if(aux != NULL && achou == 0){
		if(aux->num == num)
			achou = 1;
		else if (num < aux->num)
			achou = consultar(aux->esq, num, achou);
		else	
			achou = consultar(aux->dir, num, achou);
	}
	return achou;
}

void mostraremordem(ARVORE *aux){
	if (aux != NULL){
		mostraremordem(aux->esq);
		cout << aux->num << " ";
		mostraremordem(aux->dir);
	}
}

void mostrarpreordem(ARVORE *aux){
	if (aux != NULL){
		cout << aux->num << " ";
		mostrarpreordem(aux->esq);
		mostrarpreordem(aux->dir);
	}
}

void mostrarposordem(ARVORE *aux){
	if (aux != NULL){
		mostrarposordem(aux->esq);
		mostrarposordem(aux->dir);
		cout << aux->num << " ";
	}
}

ARVORE* remover(ARVORE* aux, int num){
	ARVORE *p, *p2;
	if(aux->num == num){
		if(aux->esq == aux->dir){
			delete aux;
			return NULL;
		}
		else if(aux->esq == NULL){
			p = aux->dir;
			delete aux;
			return p;
		}
		else if(aux->dir == NULL){
			p = aux->esq;
			delete aux;
			return p;
		}
		else{
			p2 = aux->dir;
			p = aux->dir;
			while(p->esq != NULL)
				p = p->esq;
			p->esq = aux->esq;
			delete aux;
			return p2;
		}
	}
	else if (aux->num < num)
		aux->dir = remover(aux->dir, num);
	else
		aux->esq = remover(aux->esq, num);
	return aux;
}

/* ARVORE *aux = raiz;
while (aux->esq != NULL) aux = aux->esq;
return aux->num;

ARVORE *aux = raiz;
while (aux->dir != NULL) aux = aux->dir;
return aux->num; */

ARVORE* desalocar(ARVORE* aux){
	if(aux != NULL){
		aux->esq = desalocar(aux->esq);
		aux->dir = desalocar(aux->dir);
		delete aux;
	}
	return NULL;
}

int main(){
	// a árvore está vazia, logo
	// o ponteiro raiz tem o valor null
	ARVORE *raiz = NULL;
	// o ponteiro aux é um ponteiro auxiliar
	ARVORE *aux;
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
			cin >> numero;
			raiz = inserir(raiz, numero);
			cout<<"numero inserido no inicio da arvore"; 
		}
		if(op == 2){
			if(raiz == NULL){
				cout<<"Arvore vazia";
			}
			else{
				cout << "Digite o elemento a ser consultado";
				cin >> numero;
				achou = 0;
				achou = consultar(raiz, numero, achou);
				if(achou == 0)
					cout << "Numero nao encontrado na arvore";
				else	
					cout << "Numero encontrado na arvore";
			}
		}
		if(op == 3){
			if(raiz == NULL){
				cout<<"Arvore vazia";
			}
			else{
				cout<<"Listando todos os elementos da arvore em ordem";
				mostraremordem(raiz);
			}
		}
		if(op == 4){
			if(raiz == NULL){
				cout<<"Arvore vazia";
			}
			else{
				cout<<"Listando todos os elementos da arvore pre-ordem";
				mostrarpreordem(raiz);
			}
		}
		if(op == 5){
			if(raiz == NULL){
				cout<<"Arvore vazia";
			}
			else{
				cout<<"Listando todos os elementos da arvore em pos-ordem";
				aux = raiz;
				mostrarposordem(aux);
			}
		}
		if(op == 6){
			if(raiz == NULL)
				cout << "Arvore vazia";
			else{
				cout << "Digite o numero que deseja excluir";
				cin >> numero;
				achou = 0;
				achou = consultar(raiz, numero, achou);
				if(achou == 0)
					cout <<"Numero nao encontrado na arvore";
				else{
					raiz = remover(raiz, numero);
					cout << "Numero excluido da arvore";
				}
			}
		}
		if(op == 7){
			if(raiz == NULL)
				cout << "Arvore vazia";
			else{
				raiz = desalocar(raiz);
				cout << "Arvore esvaziada";
			}
		}
	}while(op != 8);
	raiz = desalocar(raiz);
	return 1;
}