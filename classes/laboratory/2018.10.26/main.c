#include <stdio.h>
#include <stdlib.h>
#include "rb_tree.h"

extern Node * NIL_PTR;

int main (int argc, char ** argv) {
  Node * root = NULL;
  int elements[] = {90, 38, 87, 18, 86, 33, 57, 49, 25, 9};
  int n = sizeof(elements) / sizeof(elements[0]);

  for (int i = 0; i < n; i++) {
    rb_insert(&root, elements[i]);
    rb_print_inorder(root);
  }

  printf("\nAltura: %d\n", rb_height(root));
  printf("Altura negra: %d\n", rb_black_height(root));
  
  return EXIT_SUCCESS;
}
