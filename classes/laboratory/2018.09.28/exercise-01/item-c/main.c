#include <stdio.h>
#include <stdlib.h>
#include "hashing.h"

/**
 * Calcula as colisões de hashes no
 * intervalo [lower, higher].
 * 
 * @param m número de posições da tabela
 * @param lower intervalo inferior
 * @param higher intervalo superior
 * @return vetor com quantidade de colisões
 */
int * calculate_collisions (int m, int lower, int higher);

int main (int argc, char ** argv) {
  int * collisions = calculate_collisions(97, 1, 10000);
  // Abre o arquivo em modo de escrita.
  FILE * file = fopen("result.csv", "w");
  // Escreve o cabeçalho do csv.
  fprintf(file, "chave, contagem\n");

  for (int i = 0; i < 97; i++) {
    fprintf(file, "%d, %d\n", i, collisions[i]);
  }
  // Fecha o arquivo.
  fclose(file);

  return EXIT_SUCCESS;
}

int * calculate_collisions (int m, int lower, int higher) {
  // Aloca um vetor de m posições, zerando os bits.
  int * collisions = calloc(m, sizeof(int));
  for (int i = lower; i <= higher; i++) {
    // Gera o hash.
    int hash = div_hash(i, m);
    // Incrementa as colisões do hash.
    collisions[hash]++;
  }
  return collisions;
}