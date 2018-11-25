# Árvores B
*Retirado do roteiro de aula do Prof. Carlos da Silva dos Santos, CMCC/UFABC.*

Nesta aula você vai complementar o código fornecido para
implementar uma árvore B.

1. Estude o código que foi fornecido.
2. Você deve implementar a função `bt_split`, conforme a assinatura
   e descrição abaixo:

   ```c
   /**
    * Função auxiliar para particionar (fazer a cisão de) um nó.
    *
    * Entrada:
    * x: um nó que desejamos particionar.
    * Devolve: Um novo nó resultante da cisão.
    */
   bt_node* bt_split(bt_node* x) {
     /*
      * Essa função recebe um x nó completo; isto é, um
      * nó contendo (2 * t - 1) chaves.
      * 
      * A função realiza a cisão de x, criando um novo nó y
      * com a mesma capacidade t. Caso x seja uma folha,
      * y também será. Se x for um nó interno, y será um
      * nó interno.
      * 
      * As (t - 1) maiores chaves de x são copiadas para y.
      * 
      * A chave mediana de x (a chave de índice t) será copiada
      * posteriormente para o pai de x. Por isso a chave posicionada
      * no índice t do nó x deve manter o mesmo valor que tinha
      * no início da função.
      * 
      * Caso x seja um nó interno, os t filhos superiores de x
      * devem ser copiados para y.
      * 
      * Ao final da função, o número de chaves (num_keys) tanto
      * de x quanto de y deve ser (t - 1).
      * 
      * A função deve devolver o novo nó y.
      */
   }
   ```
3. Você deve criar uma função `search` com a seguinte assinatura:

   ```c
   /**
    * Busca o nó que contém determinada chave.
    *
    * Entrada:
    * T: árvore onde será feita a busca.
    * key: chave para busca.
    * Devolve: o nó que contém a chave caso ele exista,
    * NULL caso a chave não seja encontrada.
    */
   bt_node* search(bt_tree* T, int key);
   ```
4. Crie uma função que recebe uma árvore B e imprime as chaves
   contidas na árvore em ordem crescente. Para cada chave, você
   deve imprimir o par `(nivel, chave)` em que `nivel` é o
   nível de profundidade do nó em que a chave se encontra (a
   raiz tem nível zero, os filhos da raiz tem nível 1 etc.)
   e `chave` é o valor da chave.
