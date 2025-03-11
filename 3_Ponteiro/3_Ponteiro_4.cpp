/* Durante a execução de um programa, pode-se alocar dinamicamente 
memória para usar como variáveis do programa. Em C, a alocação é 
feita com a função malloc (e, para liberar memória, usa-se a função free). 
Em C++, faz-se o mesmo tipo de alocação usando o operador new 
(para liberar memória, operador delete). No exemplo a seguir, 
pode-se observar o uso das funções malloc e free:
*/

#include <stdlib.h>
#include <stdio.h>

void main()
{
 int *ptr_a;

 ptr_a = malloc(sizeof(int));
 // cria a área necessária para 01 inteiro e
 // coloca em 'ptr_a' o endereço desta área.

  if (ptr_a == NULL)
  {
    printf("Memória insuficiente!\n");
    exit(1);
  }

  printf("Endereço de ptr_a: %p\n",  ptr_a);
  *ptr_a = 90;
  printf("Conteúdo de ptr_a: %d\n", *ptr_a);  // imprime 90
  free(ptr_a);  // Libera a área alocada
}