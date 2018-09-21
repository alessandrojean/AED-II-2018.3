#include "search.h"

int seq_search (int array[], int array_size, int key) {
  for (int i = 0; i < array_size; i++) {
    // Se i é o elemento, retorne-o.
    if (array[i] == key)
      return i;
  }
  // Elemento não encontrado.
  return -1;
}

int binary_search (int array[], int array_size, int key) {
  int lo = 0, hi = array_size - 1, mid;
  while (lo <= hi) {
    mid = lo + (hi - lo) / 2;
    // Se mid é o elemento, retorne-o.
    if (array[mid] == key)
      return mid;
    // Se mid é menor que key, descarte a primeira metade.
    else if (array[mid] < key)
      lo = mid + 1;
    // Se mid é maior que key, descarte a segunda metade.
    else
      hi = mid - 1;
  }
  // Elemento não encontrado.
  return -1;
}
