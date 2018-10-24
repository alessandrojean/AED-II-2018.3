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

TreeNode * tree_successor (TreeNode * root, TreeNode * x) {
  if (root == NULL && x == NULL)
    return NULL;

  if (x->right != NULL)
    return tree_minimum(x->right);

  while (x->parent != NULL && x->parent->right == x)
    x = x->parent;

  return x->parent;
}

TreeNode * tree_predecessor (TreeNode * root, TreeNode * x) {
  if (root == NULL && x == NULL)
    return NULL;

  if (x->left != NULL)
    return tree_maximum(x->left);

  while (x->parent != NULL && x->parent->left == x)
    x = x->parent;

  return x->parent;
}

TreeNode * tree_search (TreeNode * root, Data value) {
  if (root == NULL || root->data == value)
    return root;
  if (root->data > value)
    return tree_search(root->left, value);
  return tree_search(root->right, value);
}

void tree_free (TreeNode * root) {
  if (root == NULL)
    return;

  tree_free(root->left);
  tree_free(root->right);
  free(root);
}