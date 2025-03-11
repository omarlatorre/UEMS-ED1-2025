/*Em C, pode-se imprimir o valor armazenado 
no ponteiro (um endereço), usando-se a função 
printf com o formatador %p na string de formato. 
Por exemplo:*/

#include <stdio.h>
void main()
{
  int x;
  int *ptr;
  ptr = &x;
  printf("O endereço de X é: %p\n", ptr);
}