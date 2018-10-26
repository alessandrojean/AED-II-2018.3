#ifndef RB_TREE_H_INCLUDED
#define RB_TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define PAR(x) (x)->parent
#define GPAR(x) (x)->parent->parent

typedef enum {BLACK, RED} Color;

typedef struct Node {
  int key;
  Color color;
  struct Node *left;
  struct Node *right;
  struct Node *parent;
} Node;

void rb_insert (Node ** T, int key);
int rb_height (Node * T);
int rb_black_height (Node * T);

#endif // RB_TREE_H_INCLUDED
