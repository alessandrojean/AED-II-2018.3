/**
 * Efetua uma busca sequencial no vetor,
 * buscando por um elemento igual a key.
 * 
 * @param array vetor para busca
 * @param array_size número de elementos do vetor
 * @param key elemento para buscar
 * @return posição do elemento key se achar, -1 caso contrário
 */
int seq_search (int array[], int array_size, int key);

/**
 * Efetua uma busca binária no vetor,
 * buscando por um elemento igual a key.
 * 
 * @param array vetor para busca
 * @param array_size número de elementos do vetor
 * @param key elemento para buscar
 * @return posição do elemento key se achar, -1 caso contrário
 */
int binary_search (int array[], int array_size, int key);
