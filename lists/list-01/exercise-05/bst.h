#ifndef BST_H_
#define BST_H_

typedef struct tree_node TreeNode;
typedef int Data;

struct tree_node {
  Data data;
  TreeNode * parent;
  TreeNode * left;
  TreeNode * right;
};

TreeNode * create_node (Data value);
TreeNode * tree_insert (TreeNode * root, Data value);
TreeNode * tree_minimum (TreeNode * root);
TreeNode * tree_maximum (TreeNode * root);
TreeNode * tree_successor (TreeNode * root, TreeNode * x);
TreeNode * tree_predecessor (TreeNode * root, TreeNode * x);
TreeNode * tree_search (TreeNode * root, Data value);
void tree_free (TreeNode * root);

#endif // BST_H_