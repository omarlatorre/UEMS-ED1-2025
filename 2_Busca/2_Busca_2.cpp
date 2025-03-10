#include <iostream>
#include <string.h>
using namespace std;

struct tFuncionario
{
    int matricula;
    char sexo;
    string nome;
    string telefone;
};

int buscaSequencial(tFuncionario v[], int size, int l)
{
	for (int i = 0; i < size; i++)
	{
		if (v[i].matricula == l)
		{
			cout << "preciso de n tentativas: " << i << endl;
			return 1;
		}
	}
	cout << "nao encontrei o elemento" << endl;
	return 0;
}


int buscaBinaria(tFuncionario v[], int size, int l)
{
	int min = 0;
	int max = size - 1;
	int med;
	int count = 0;

	while (min <= max)
	{
		med = (max + min) / 2;
		if (l == v[med].matricula)
		{
			cout << "Valor encontrado em n tentativas: " << count << endl;
			return med;
		}
		else if (l < v[med].matricula)
		{
			count++;
			max = med - 1;
		}
		else
		{
			count++;
			min = med + 1;
		}
	}

	cout << "Valor nao encontrado" << endl;
	return 0;
}

void lerFuncionario(tFuncionario Func[], int size){
    for (int i = 0; i < size; i++)
    {
        cout << "Insere o numero de matricula ";
        cin >> Func[i].matricula;
        cout << "Insere o nome ";
        cin >> Func[i].nome;
        cout << "Insere o sexo ";
        cin >> Func[i].sexo;
        cout << "Insere o telefone de contato ";
        cin >> Func[i].telefone;
    }
}

void imprimeFuncionario(tFuncionario Func[], int size){
    for (int i = 0; i < size; i++)
    {
        cout << Func[i].matricula << endl;
        cout << Func[i].nome << endl;
        cout << Func[i].sexo << endl;
        cout << Func[i].telefone << endl;
    }
}

int main()
{
    int MAX = 3;
    int chave;
    tFuncionario Func[MAX];
    lerFuncionario(Func, MAX);
    imprimeFuncionario(Func, MAX);
    cout << "Insire uma chave matricula ";
    cin >> chave;

	buscaSequencial(Func, MAX, chave);
	buscaBinaria(Func, MAX, chave);

	system("pause");
	return 0;
}