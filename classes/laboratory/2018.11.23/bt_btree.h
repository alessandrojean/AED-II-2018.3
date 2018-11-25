#ifndef BT_BTREE_H_
#define BT_BTREE_H_

#include <stdbool.h>
#include <stdlib.h>

/**
 * Representa um nó (célula) de uma árvore B.
 */
struct bt_node {
  /**
   * Cada chave é representada por um numero inteiro
   * `keys' guarda a sequência de chaves para um determinado nó.
   */
  int* keys;

  /**
   * Guarda a sequência de filhos de um determinado nó.
   */
  struct bt_node** children;

  /**
   * Sinaliza se este nó é uma folha ou não.
   */
  bool is_leaf;

  /**
   * Número atual de chaves armazenadas.
   */
  int num_keys;

  /**
   * Parâmetro que determina a capacidade de um nó;
   * cada nó pode ter até (2 * t - 1) chaves e até 2 * t filhos.
   */
  int t;
};

typedef struct bt_node bt_node;

/**
 * Representa uma árvore B.
 */
struct bt_tree {
  /**
   * Nó raiz da arvore.
   */
  bt_node* root;
  /**
   * Capacidade dos nós da árvore.
   */
  int t;
};

typedef struct bt_tree bt_tree;

/**
 * Cria uma nova árvore, inicialmente vazia.
 *
 * @param t parâmetro de capacidade dos nós da árvore.
 * @return ponteiro para a árvore recém criada.
 */
bt_tree* new_tree(int t);

/**
 * Cria um novo nó.
 *
 * @param t parâmetro de capacidade do nó.
 * @param is_leaf determina se o novo nó será uma folha ou não.
 * @return novo nó.
 */
bt_node* bt_new_node(int t, bool is_leaf);

/**
 * Busca o nó que contém determinada chave.
 *
 * @param T árvore onde será feita a busca.
 * @param key chave para busca.
 * @return o nó que contém a chave caso ele exista,
 * NULL caso a chave não seja encontrada.
 */
bt_node* search(bt_tree* T, int key);

/**
 * Insere uma nova chave na árvore.
 *
 * @param T árvore onde a chave será inserida.
 * @param key nova chave a ser inserida.
 * @return 0 em caso de sucesso, outro valor
 * caso não seja possível inserir a chave.
 */
int bt_insert(bt_tree* T, int key);

/**
 * Insere uma nova chave em um nó que ainda
 * não esteja completo.
 *
 * @param N um nó ainda não completo, abaixo do qual
 * será inserida a nova chave. A inserção não ocorrerá
 * necessariamente em N, a chave pode ser inserida
 * em alguma folha que seja descendente de N.
 * @param key a chave a ser inserida.
 * @return 0 em caso de sucesso, outro valor
 * caso não seja possível inserir a chave.
 */
int bt_insert_non_full(bt_node* N, int key);

/**
 * Realiza a cisão de um nó (célula) da árvore.
 *
 * Ao final dessa função, o nó `child' terá sido
 * particionado em dois. No início da função, o nó
 * `child' deve estar completo (2 * t - 1 chaves).
 * As (t - 1) chaves superiores de `child' serão
 * copiadas para um novo nó, que será acrescentado
 * à arvore. O nó original `child' terá (t - 1)
 * chaves ao final da execução.
 *
 * O novo nó resultante será adicionado a árvore,
 * logo abaixo de `parent'.
 *
 * @param parent nó pai do nó que será particionado.
 * @param index índice do nó `child' que será particionado
 * em relação a sequência de filhos de `parent'.
 * @param child nó a ser particionado em dois.
 * @return 0 em caso de sucesso, outro valor
 * caso não seja particionar o nó.
 */
int bt_split_child(bt_node* parent, int index, bt_node* child);

/**
 * Função auxiliar para particionar
 * (fazer a cisão de) um nó.
 *
 * @param x um nó que desejamos particionar.
 * @return Um novo nó resultante da cisão.
 */
bt_node* bt_split(bt_node* x);

/**
 * Imprime as chaves deuma árvore B em ordem
 * crescente, no formato (nível, chave).
 * 
 * @param T árvore B a ser impressa.
 */
void bt_print(bt_tree* T);

#endif // BT_BTREE_H_
