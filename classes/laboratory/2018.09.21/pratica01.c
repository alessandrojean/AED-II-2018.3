#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "search.h"

/**
 * Lê um vetor de inteiros, com n elementos.
 * 
 * @param array vetor para ler
 * @param array_size número de elementos do vetor
 */
void read_array (int array[], int array_size);

/**
 * Calcula o tempo passado em nanosegundos.
 * 
 * @param t_start tempo de início
 * @param t_end tempo de fim
 */
double calculate_time_elapsed (clock_t t_start, clock_t t_end);

int main (int argc, char ** argv) {
  int n;
  scanf("%d", &n);

  // Aloca um vetor de n inteiros.
  int * array = malloc(sizeof(int) * n);
  read_array(array, n);

  int key;
  scanf("%d", &key);

  // Variáveis de medida de tempo.
  clock_t t_start, t_end;

  t_start = clock();
  printf("Busca sequencial: %d\n", seq_search(array, n, key));
  t_end = clock();
  printf("Tempo (ns): %.2f\n", calculate_time_elapsed(t_start, t_end));

  t_start = clock();
  printf("\nBusca binária: %d\n", binary_search(array, n, key));
  t_end = clock();
  printf("Tempo (ns): %.2f\n", calculate_time_elapsed(t_start, t_end));
  
  return EXIT_SUCCESS;
}

void read_array (int array[], int array_size) {
  for (int i = 0; i < array_size; i++)
    scanf("%d", &array[i]);
}

double calculate_time_elapsed (clock_t t_start, clock_t t_end) {
  return 1e6 * (double) (t_end - t_start) / CLOCKS_PER_SEC;
}
