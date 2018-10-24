#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main (int argc, char **argv) {
  Data values[] = {5, 1, 4, 7, 8, 10, -1, 2};
  int n = sizeof(values) / sizeof(values[0]);
  TreeNode * tree = NULL;

  for (int i = 0; i < n; i++)
    tree = tree_insert(tree, values[i]);

  printf("Minimum: %d\n", tree_minimum(tree)->data);
  printf("Maximum: %d\n", tree_maximum(tree)->data);

  TreeNode * eight = tree_search(tree, 4);
  printf("Predecessor of 8: %d\n", tree_predecessor(tree, eight)->data);
  printf("Successor of 8: %d\n", tree_successor(tree, eight)->data);

  tree_free(tree);

  return EXIT_SUCCESS;
}
