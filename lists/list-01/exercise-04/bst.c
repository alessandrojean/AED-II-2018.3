#include <stdlib.h>
#include "bst.h"

TreeNode * create_node (Data value) {
  TreeNode * new_node = malloc(sizeof(TreeNode));
  if (new_node != NULL) {
    new_node->data = value;
    new_node->left = new_node->right = new_node->parent = NULL;
  }
  return new_node;
}

TreeNode * tree_insert (TreeNode * root, Data value) {
  if (root == NULL)
    return create_node(value);

  if (value < root->data) {
    TreeNode * result = tree_insert(root->left, value);
    if (result != NULL) {
      root->left = result;
      result->parent = root;
    }
  } else if (value > root->data) {
    TreeNode * result = tree_insert(root->right, value);
    if (result != NULL) {
      root->right = result;
      result->parent = root;
    }
  }

  return root;
}

TreeNode * tree_minimum (TreeNode * root) {
  while (root != NULL && root->left != NULL)
    root = root->left;
  return root;
}

TreeNode * tree_maximum (TreeNode * root) {
  while (root != NULL && root->right != NULL)
    root = root->right;
  return root;
}

void tree_free (TreeNode * root) {
  if (root == NULL)
    return;

  tree_free(root->left);
  tree_free(root->right);
  free(root);
}