#include <iostream>

int buscaSequencial(int v[], int size, int l)
{
	for (int i = 0; i < size; i++)
	{
		if (v[i] == l)
		{
			std::cout << "preciso de n tentativas: " << i << std::endl;
			return 1;
		}
	}
	std::cout << "nao encontrei o elemento" << std::endl;
	return 0;
}


int buscaBinaria(int v[], int size, int l)
{
	int min = v[0];
	int max = v[size - 1];
	int med;
	int count = 0;

	while (min <= max)
	{
		med = (max + min) / 2;
		if (l == v[med])
		{
			std::cout << "Valor encontrado em n tentativas: " << count << std::endl;
			return med;
		}
		else if (l < v[med])
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

	std::cout << "Valor nao encontrado" << std::endl;
	return 0;
}

int main()
{
	int vetor[1000];
	
	for (int i = 0; i < 1000; i++)
	{
		vetor[i] = i;
	}

	buscaSequencial(vetor, 1000, 400);
	buscaBinaria(vetor, 1000, 400);

	system("pause");
	return 0;
}