/* Para acessar o conteúdo de uma posição de memória, cujo endereço está 
armazenado em um ponteiro, usa-se o operador de derreferência (*). 
Por exemplo:
*/

#include <stdio.h>
void main()
{
  int x;
  int *ptr;
  x = 5;
  ptr = &x;
  printf("O valor da variável X é: %d\n", *ptr);  // derreferenciando um ponteiro
  *ptr = 10;  // usando derreferencia no "lado esquerdo" de uma atribuição
  printf("Agora, X vale: %d\n", *ptr);
}