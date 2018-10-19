#include "rb_tree.h"

/* Valor de sentinela, indica que chegamos em alguma folha ou entao
 a raiz da arvore */
Node NIL_NODE;

/* Ponteiro para o valor de sentinela */
Node *NIL_PTR = &NIL_NODE;

/** 
 * Funcao auxiliar que cria um novo Node, alocando memoria,
 * para um valor de chave passado como parametro.
 * Note que os valores dos ponteiros left/right/parent sao
 * mantidos como NULL
 *
 * Parametros:
 * key: a chave para o novo Node
 *
 * Devolve:
 * Um novo Node em caso de sucesso, NULL caso nao consiga alocar
 * a memoria para o novo Node
 */
Node* new_node (int key) {
  Node *ret_val = (Node*) malloc(sizeof(Node));
  if (NULL == ret_val) return NULL;
  ret_val->key = key;
  ret_val->color = RED;
  ret_val->left = NULL;
  ret_val->right = NULL;
  ret_val->parent = NULL;
  return ret_val;
}

/**
 * A funcao abaixo insere uma nova chave em uma arvore RB
 * sem realizar o balanceamento.
 *
 * Parametros:
 * T: aponta para a raiz da arvore onde devemos inserir a chave
 * key: valor da nova chave
 *
 * Devolve:
 * O novo Node inserido em caso de sucesso, NULL caso nao
 * seja possivel inserir o novo valor
 */
Node* tree_insert (Node** T, int key){
  if (*T == NULL) {
    Node * new = new_node(key);
    if (new != NULL) {
      *T = new;
      new->color = BLACK;
      new->left = new->right = NIL_PTR;
    }
    return new;
  }

  Node * current = *T, * previous = *T;
  while (current != NIL_PTR) {
    if (current->key == key) return NULL;
    previous = current;
    current = (key < current->key) ? current->left : current->right;
  }

  Node * new = new_node(key);
  if (new != NULL) {
    new->left = new->right = NIL_PTR;
    new->parent = previous;

    if (key < previous->key)
      previous->left = new;
    else
      previous->right = new;
  }

  return new;
}

/**
 * Realiza uma rotacao simples para a esquerda
 *
 * Parametros:
 * T: aponta para a raiz da arvore onde a rotacao sera realizada
 * x: Node pertencente a arvore em torno do qual faremos a rotacao
*/
void left_rotate (Node** T, Node* x) {
  Node * y = x->right;
  x->right = y->left;
  y->left = x;

  if (x->parent != NULL && x->parent->right == x)
    x->parent->right = y;
  else if (x->parent != NULL && x->parent->left == x)
    x->parent->left = y;

  y->parent = x->parent;
  x->parent = y;

  if (*T == x)
    *T = y;
}

/**
 * Realiza uma rotacao simples para a direita
 *
 * Parametros:
 * T: aponta para a raiz da arvore onde a rotacao sera realizada
 * x: Node pertencente a arvore em torno do qual faremos a rotacao
*/
void right_rotate (Node** T, Node* x) {
  Node * y = x->left;
  x->left = y->right;
  y->right = x;

  if (x->parent != NULL && x->parent->right == x)
    x->parent->right = y;
  else if (x->parent != NULL && x->parent->left == x)
    x->parent->left = y;

  y->parent = x->parent;
  x->parent = y;

  if (*T == x)
    *T = y;
}


/**
 * Realiza a troca de cor em alguns nos, caso esses satisfacam
 * algumas condicoes.
 *
 * Parametros:
 * T: aponta para a raiz da arvore onde a rotacao sera realizada
 * z: Node pertencente a arvore em torno do qual faremos a rotacao
*/
void flip_color (Node** T, Node* z) {
  Node * p = z->parent;
  Node * a = p->parent;
  Node * t = (a->left == p) ? a->right : a->left;

  if (z->color == RED && p->color == RED 
      && t->color == RED && a->color == BLACK) {
    p->color = BLACK;
    t->color = BLACK;
    a->color = RED;
  }
}


