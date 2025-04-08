/* Lista Sequencial 
* Implementada sobre um vetor de inteiros 
*/
#include <iostream>
using namespace std;

const int MAXLISTA = 10;

struct Lista{
    int dados[MAXLISTA];
    int ult, pc, nelem;
};

Lista aLista;

void inicializarFila(){
    aLista.pc = aLista.ult = -1;
	aLista.nelem = 0;
}

// insercao no final da lista
void insere(int item)
{
    if (aLista.nelem == MAXLISTA) 
        printf("Erro Lista cheia");
    aLista.ult++;
    aLista.dados[aLista.ult] = item;
    aLista.nelem ++;	
}

// insercao na posicao pos
void insere_pos(int item, int pos)
{
    if (aLista.nelem == MAXLISTA) 
        printf("Erro Lista cheia");

    if ((pos < 0) || (pos > aLista.ult))
        printf("Posicao invalida");

    for (int i = aLista.ult; i >= pos; i--)
        aLista.dados[i+1] = aLista.dados[i];

    aLista.ult++;
    aLista.dados[pos] = item;
    aLista.nelem++;
}

// remocao na posicao pos
void remove_pos(int pos)
{
    if (aLista.nelem == 0) 
        printf("Lista vazia");

    if ((pos<0) || (pos > aLista.ult))
        printf("Posicao invalida");

    for (int i = pos; i < aLista.ult; i++)
        aLista.dados[i] = aLista.dados[i+1];
    aLista.ult--;
    aLista.nelem--;
}

int elemento(int pos) {
    if ((pos < 0) || (pos > aLista.ult))
        printf("Posicao invalida");
    return aLista.dados[pos];
}

//pesquisa
int pesquisa(int item)
{
    int i;
    for (i = 0; i <= aLista.ult; i++)
        if (aLista.dados[i] == item)
            break;
    if(i == aLista.ult + 1)
        return (-1);
    else
        return i;
}

// remove o elemento item da lista
void remove(int item) 
{
    int p;
    if (aLista.nelem == 0) 
        printf("Lista vazia");

    for (p = 0; p <= aLista.ult; p++)
        if (aLista.dados[p] == item)
            break;
    if (p > aLista.ult) 
        printf("Nao esta na lista");

    for (int i = p; i < aLista.ult; i++)
        aLista.dados[i] = aLista.dados[i+1];
    aLista.ult--;
    aLista.nelem--;
}

void volta_cursor()
{
    aLista.pc = -1;
}

bool tem_proximo()
{
    return(aLista.pc != aLista.ult);	
}
	
int proximo()
{
    if (aLista.pc == aLista.ult) 
        printf("Nao ha proximo");
    aLista.pc++;
    return(aLista.dados[aLista.pc]);
}

void printDados(){
    while(tem_proximo()){
        cout << proximo() << endl;
    }
    volta_cursor();
}

int menu(){
    int opcao;
    cout << "1. Insere fim da lista " << "\n";
    cout << "2. Insere na posicao pos " << "\n";
    cout << "3. Remove a posicao pos " << "\n";
    cout << "4. Remove elemento " << "\n";
    cout << "5. Busca elemento " << "\n";
    cout << "6. Imprime lista " << "\n";
    cout << "7. Sair " << "\n";
    cout << "Insira opcao [1-7]  ";
    cin >> opcao;
    return opcao;
}

int main(){
    inicializarFila();
    int flag = 1, opcao, item, pos;
    while (flag){
        opcao = menu();
        switch (opcao){
        case 1:
            cout << "Insira item no fim da lista ";
            cin >> item;
            insere(item); break;
        case 2: 
            cout << "Inserindo na posicao pos na lista " << "\n";
            cout << "Insira o item ";
            cin >> item;
            cout << "Insira a posicao pos ";
            cin >> pos;
            insere_pos(item, pos); break;
        case 3: 
            cout << "Removendo elto da posicao pos na lista " << "\n";
            cout << "Insira a posicao pos ";
            cin >> pos;
            remove_pos(pos); break;
        case 4: 
            cout << "Removendo elto da lista " << "\n";
            cout << "Insira o item a ser removido ";
            cin >> item;
            remove(item); break;
        case 5:
            cout << "Insira elto a ser pesquisado " << "\n";
            cin >> item;
            pos = pesquisa(item);
            pos == -1 ? printf("Nao esta na lista\n"): printf("Item na posicao %d\n", pos); break;     
        case 6:
            cout << "Mostrando todos os dados da Lista" << "\n";
            printDados(); break;    
        case 7:
            cout << "Saindo do menu " << "\n";
            flag = 0;       
        default:
            break;
        }
    }
    return 0;
}