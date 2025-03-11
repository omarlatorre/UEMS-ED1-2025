/*Nos exemplos anteriores, foi alocado um espaço para armazenar apenas um dado 
do tipo int. Entretanto, é mais comum utilizar ponteiros para alocação de 
vetores. Para tanto, basta especificar o tamanho desse vetor no momento da 
alocação. Nos exemplos abaixo, apresenta-se a alocação de vetores com malloc 
e new. Após a alocação de uma área com vários elementos, ela pode ser 
acessada exatamente como se fosse um vetor.
Exemplo em C:
*/

#include <stdlib.h>
#include <stdio.h>
void main()
{
  int i;
  int *v;
  v = (int*)malloc(sizeof(int)*10);  // 'v' é um ponteiro para uma área que
                                     // tem 10 inteiros.
                                     // 'v' funciona exatamente como um vetor
  v[0] = 10;
  v[1] = 11;
  v[2] = 12;
  // continua...
  v[9] = 19;

  for(i = 0; i < 10; i++)
    printf("v[%d]: %d\n", i, v[i]);

  printf("Endereço de 'v': %p", v);  // imprime o endereço da área alocada para 'v'
  free(v);
}