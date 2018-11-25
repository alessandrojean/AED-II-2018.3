#include "bt_btree.h"
#include <stdbool.h>
#include <stdio.h>

bt_tree* new_tree(int t) {
  // Cria uma árvore vazia, com a raiz inicialmente nula.
  bt_tree* tree = malloc(sizeof(bt_tree));
  if (!tree) return NULL;
  tree->t = t;
  tree->root = NULL;
  return tree;
}

bt_node* bt_new_node(int t, bool is_leaf) {
  bt_node* node = malloc(sizeof(bt_node));
  if (!node) return NULL;
  // O nó tem capacidade para até 2 * t filhos e (2 * t - 1) chaves.
  node->keys = malloc((2 * t - 1) * sizeof(int));
  if (node->keys == NULL) {
    free(node);
    return NULL;
  }
  node->children = malloc(2 * t * sizeof(bt_node*));
  if (!node->children) {
    free(node->keys);
    free(node);
    return NULL;
  }
  node->is_leaf = is_leaf;
  node->t = t;
  // Nó inicio é vazio.
  node->num_keys = 0;
  return node;
}

int bt_insert(bt_tree* T, int key) {
  if (!T) return -1;
  int t = T->t;
  if (T->root == NULL) {
    // Se a árvore ainda estiver vazia, vamos criar um novo nó
    // com a chave e então esse nó torna-se a raiz da árvore.
    T->root = bt_new_node(t, true);
    if (T->root == NULL) return -1;
    T->root->keys[0] = key;
    T->root->num_keys = 1;
  } else {
    // A raiz já est[a] completa então é preciso
    // fazer a cisão da raiz antes de inserir a nova chave.
    if ((2 * t - 1) == T->root->num_keys) {
      // Cria-se um nó para ser a nova raiz.
      bt_node* n = bt_new_node(T->t, false);
      // A antiga raiz torna-se o único filho da nova raiz.
      n->children[0] = T->root;
      T->root = n;
      // Agora particionamos o nó que
      // estava completo (antiga raiz).
      bt_split_child(n, 0, n->children[0]);
      // Finalmente inserimos a nova chave.
      bt_insert_non_full(n, key);
    } else {
      // A raiz não está completa, então usamos a
      // função de inserção apropriada.
      bt_insert_non_full(T->root, key);
    }
  }
  return 0;
}

int bt_insert_non_full(bt_node* N, int key) {
  if (!N) return -1;
  // Índice da maior chave de N.
  int i = N->num_keys - 1;
  if (N->is_leaf) {
    // Se o nó atual é uma folha, apenas
    // deslocamos as chaves maiores, criando
    // o espaço para inserir a chave diretamente
    // no nó atual.
    while (key < N->keys[i] && i >= 0) {
      // Desloca as chaves enquanto localiza o ponto de inserção.
      N->keys[i + 1] = N->keys[i];
      i--;
    }
    i++;
    // Inserimos a chave e incrementamos o contador de chaves.
    N->keys[i] = key;
    N->num_keys += 1;
    return 0;
  } else {
    // O nó atual não é folha; localiza o nó
    // filho em que devemos prosseguir com a inserção.
    while (key < N->keys[i] && i >= 0) {
      i--;
    }
    i++;
    // Nó filho em baixo do qual devemos inserir a chave.
    bt_node* child = N->children[i];
    if (2 * (child->t) - 1 == child->num_keys) {
      // Se o filho está completo, devemos
      // fazer a cisão e prosseguir.
      bt_split_child(N, i, child);
      if (key > N->keys[i]) i++;
    }
    return bt_insert_non_full(N->children[i], key);
  }
}

int bt_split_child(bt_node* parent, int index, bt_node* child) {
  // Faz a cisão de child, criando um novo nó.
  // As chaves superiores de child são copiadas no novo nó.
  bt_node* new_child = bt_split(child);
  int t = parent->t;
  // Desloca os filhos, abrindo espaço para o novo nó.
  for (int j = parent->num_keys; j >= index + 1; j--) {
    parent->children[j + 1] = parent->children[j];
  }
  // Acrescenta o nó recém criado em parent.
  parent->children[index + 1] = new_child;
  // Desloca as chaves existentes em
  // parent para criar espaço para
  // a chave mediana de child.
  for (int j = parent->num_keys - 1; j >= index; j--) {
    parent->keys[j + 1] = parent->keys[j];
  }
  // A chave mediana de child é transportada para o pai.
  parent->keys[index] = child->keys[t - 1];
  // Com acrescimo no novo nó e chave,
  // incrementamos o contador de chaves.
  parent->num_keys += 1;
  return 0;
}

bt_node* bt_split(bt_node* x) {
  // Essa função recebe um x nó completo; isto é,
  // um nó contendo (2*t -1) chaves. A função realiza a
  // cisão de x, criando um novo nó y com a mesma capacidade t.
  // Caso x seja uma folha, y tambem será.
  // Se x for um nó interno, y será um nó interno.
  bt_node* y = bt_new_node(x->t, x->is_leaf);
  // As (t-1) maiores chaves de x são copiadas para y.
  for (int i = 0; i < x->t - 1; i++) {
    y->keys[i] = x->keys[i + x->t];
  }
  // A chave mediana de x (a chave de índice t)
  // será copiada posteriormente para o pai de x.
  // Por isso a chave posicionada no índice t do
  // nó x deve manter o mesmo valor que tinha no
  // início da função.
  // Caso x seja um nó interno, os t filhos
  // superiores de x devem ser copiados para y.
  if (!x->is_leaf) {
    for (int i = 0; i < x->t; i++) {
      y->children[i] = x->children[i + x->t - 1];
    }
  }
  // Ao final da função, o número de chaves
  // (num_keys) tanto de x quanto de y deve ser (t - 1).
  x->num_keys = y->num_keys = x->t - 1;
  // A função deve devolver o novo no y.
  return y;
}

bt_node* search(bt_tree* T, int key) {
  if (T == NULL) return NULL;

  bt_node* root = T->root;
  while (root != NULL) {
    for (int i = 0; i < root->num_keys; i++) {
      if (root->keys[i] == key) return root;

      if (key < root->keys[i] && root->is_leaf) {
        root = NULL;
        break;
      }

      if (key < root->keys[i]) {
        root = root->children[i];
        break;
      }

      if (i == root->num_keys - 1 && key > root->keys[i]) {
        root = root->children[root->num_keys];
        break;
      }
    }
  }

  return NULL;
}

void bt_print_recursive(bt_node* node, int depth) {
  if (node == NULL) return;

  for (int i = 0; i < node->num_keys; i++) {
    bt_print_recursive(node->children[i], depth + 1);
    printf("(%d, %d) ", depth, node->keys[i]);
  }

  bt_print_recursive(node->children[node->num_keys], depth + 1);
}

void bt_print(bt_tree* T) {
  if (T == NULL) return;

  bt_print_recursive(T->root, 0);
  printf("\n");
}
