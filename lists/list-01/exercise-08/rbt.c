#include <stdlib.h>
#include "rbt.h"

RBTreeNode * create_node (Data value) {
  RBTreeNode * new_node = malloc(sizeof(RBTreeNode));
  if (new_node != NULL) {
    new_node->data = value;
    new_node->color = RED;
    new_node->parent = NULL;
    new_node->left = new_node->right = NULL;
  }
  return new_node;
}

int black_height (RBTreeNode * root) {
  if (root == NIL_PTR)
    return 0;

  int h_left = black_height(root->left);

  if (root->color == RED)
    return h_left;
  return h_left + 1;
}
