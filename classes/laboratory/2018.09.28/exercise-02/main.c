#include <stdio.h>
#include <stdlib.h>
#include "hashing.h"

/**
 * Calcula os hashes utilizando o método
 * da multiplicação, no intervalo [lower, higher].
 * 
 * @param m número de posições da tabela
 * @param a constante não negativa, 0 < a < 1
 * @param lower intervalo inferior
 * @param higher intervalo superior
 * @return vetor de hashes gerados
 */
int * calculate_hashes (int m, float a, int lower, int higher);
/**
 * Escreve o conteúdo do vetor collisions
 * em um arquivo no formado .csv.
 * 
 * @param collisions vetor resultado
 * @param fileName nome do arquivo
 */
void write_to_file (int * collisions, char * fileName);

int main (int argc, char ** argv) {
  int * collisionsA = calculate_hashes(200, 0.62, 1, 500000);
  int * collisionsB = calculate_hashes(200, 0.61803398875, 1, 500000);

  write_to_file(collisionsA, "resultA.csv");
  write_to_file(collisionsB, "resultB.csv");

  return EXIT_SUCCESS;
}

int * calculate_hashes (int m, float a, int lower, int higher) {
  // Aloca um vetor de m posições, zerando os bits.
  int * collisions = calloc(m, sizeof(int));
  for (int i = lower; i <= higher; i++) {
    // Calcula o hash.
    int hash = mul_hash(i, m, a);
    // Incrementa a contagem de colisões.
    collisions[hash]++;
  }
  return collisions;
}

void write_to_file (int * collisions, char * fileName) {
  // Abre o arquivo no modo de escrita.
  FILE * file = fopen(fileName, "w");
  // Escreve o cabeçalho do csv.
  fprintf(file, "chave, contagem\n");

  for (int i = 0; i < 97; i++) {
    fprintf(file, "%d, %d\n", i, collisions[i]);
  }
  // Fecha a escrita do arquivo.
  fclose(file);
}