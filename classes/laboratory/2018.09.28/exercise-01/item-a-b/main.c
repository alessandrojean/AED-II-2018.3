#include <stdio.h>
#include <stdlib.h>
#include "hashing.h"

/**
 * Calcula os hashs no intervalo de [lower, higher],
 * utilizando utilizando m para o cálculo do hash
 * de divisão. A cada hash gerado, a função
 * element é chamada.
 * 
 * @param m número de elementos do vetor final do hash
 * @param lower intervalo inferior
 * @param higher intervalo superior
 * @param element função chamada a cada hash gerado
 */
void calculate_hash (int m, int lower, int higher, void (*element)(int, int));
/**
 * Imprime a chave e o hash se
 * o hash gerado for igual a 3.
 * 
 * @param key chave do hash gerado
 * @param hash hash gerado
 */
void print_if_three (int key, int hash);
/**
 * Imprime a chave e o hash.
 * 
 * @param key chave do hash gerado
 * @param hash hash gerado
 */
void print_item (int key, int hash);

int main (int argc, char ** argv) {
  /* 
   * Item a)
   * 
   * Os resultados dos múltiplos de 3
   * a cada 12 números gera um hash de 3.
   */
  printf("m = 12\n");
  calculate_hash(12, 0, 100, &print_if_three);

  /*
   * Item b)
   * 
   * Com m = 11, variando de 0 a 100,
   * os hashes gerados sempre vão variando
   * de 0 a 10 em ordem. Ou seja,
   * iniciam em 0 até 10 e depois reseta
   * e começa em 0 novamente.
   */
  printf("\nm = 11\n");
  calculate_hash(11, 0, 100, &print_item);

  return EXIT_SUCCESS;
}

void calculate_hash (int m, int lower, int higher, void (*element)(int, int)) {
  for (int i = lower; i <= higher; i++) {
    // Calcula o hash.
    int hash = div_hash(i, m);
    // Chama a função passada como ponteiro.
    (*element)(i, hash);
  }
}

void print_if_three (int key, int hash) {
  if (hash == 3)
    printf("%3d -> %2d\n", key, hash);
}

void print_item (int key, int hash) {
  printf("%3d -> %2d\n", key, hash);
}