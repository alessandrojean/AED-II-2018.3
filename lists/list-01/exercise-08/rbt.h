#ifndef RBT_H_
#define RBT_H_

typedef int Data;
typedef struct rb_tree_node RBTreeNode;
typedef enum {RED, BLACK} Color;

static const RBTreeNode NIL_NODE;
static const RBTreeNode * NIL_PTR = &NIL_NODE;

struct rb_tree_node {
  Data data;
  Color color;
  RBTreeNode * parent;
  RBTreeNode * left;
  RBTreeNode * right;
};

RBTreeNode * create_node (Data value);
int black_height (RBTreeNode * root);

#endif // RBT_H_