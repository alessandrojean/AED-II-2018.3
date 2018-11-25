#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "bt_btree.h"

#define T 3

/**
 * Imprime corretamente o resultado de uma
 * busca em uma árvore B pela chave `key'.
 *
 * @param tree árvore B para a busca.
 * @param key chave a ser buscada.
 * @return o nó que contém a chave, caso exista.
 */
void print_search(bt_tree* tree, int key);

int main(int argc, char** argv) {
  bt_tree* tree = new_tree(T);
  int elements[] = {2, 4, 8, 10, 13, 12};
  int n = sizeof(elements) / sizeof(elements[0]);

  for (int i = 0; i < n; i++) {
    bt_insert(tree, elements[i]);
  }

  bt_print(tree);

  print_search(tree, 2);

  return EXIT_SUCCESS;
}

void print_search(bt_tree* tree, int key) {
  bt_node* result = search(tree, key);

  if (result == NULL) {
    printf("Chave %d não encontrada.\n", key);
    return;
  }

  printf("Chave %d encontrada no nó [", key);
  for (int i = 0; i < result->num_keys; i++) {
    printf("%d%s", result->keys[i], i < result->num_keys - 1 ? ", " : "].\n");
  }
}
