#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main (int argc, char **argv) {
  Data values[] = {5, 1, 4, 7, 8, 10, -1, 2};
  int n = sizeof(values) / sizeof(values[0]);
  TreeNode * tree = NULL;

  for (int i = 0; i < n; i++)
    tree = tree_insert(tree, values[i]);

  printf("5th minimum: %d\n", tree_nth_minimum(tree, 5)->data);

  tree_free(tree);

  return EXIT_SUCCESS;
}
