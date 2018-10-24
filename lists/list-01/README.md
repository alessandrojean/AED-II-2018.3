# Lista de Exercícios 1
*Lista de exercícios do Prof. Carlos da Silva dos Santos, CMCC/UFABC.*

1. Considere uma tabela de dispersão em que as colisões são resolvidas
   por encadeamento. Seja `n` o número de chaves distintas e `m`
   o tamanho da tabela (tamanho do vetor usado para armazenar
   elementos). A função de espalhamento `h(k)` obedece à condição
   de espalhamento uniforme (cada chave tem a mesma probabilidade
   de ser mapeada em qualquer posição da tabela). Calcule a quantidade
   esperada de colisões, isto é, calcule a quantidade esperada de
   pares `{h, l}` distintos em que `h` e `l` são chaves, `h ≠ l`
   e `h(k) = h(l)`.

2. Considere uma tabela de dispersão de tamanho `m = 9` em que
   as colisões são resolvidas por encadeamento. A função
   de dispersão é dada por `h(k) = k mod 9`. Uma sequência
   de chaves é inserida na seguinte ordem:
   `{19, 12, 5, 33, 28, 17, 20, 10, 29}`. Faça um diagrama
   representando a configuração da tabela ao final das
   inserções (para cada posição da tabela, represente
   a lista ligada correspondente).

3. Considere uma árvore binária de busca `T` em que as chaves
   são números naturais. Sabendo que as chaves são inseridas
   (sem balanceamento) na seguinte ordem:
   `{20, 25, 17, 26, 31, 12, 18, 12}`

   1. Desenhe a árvore `T` resultante.

   2. Tente encontrar uma outra ordem de inserção das chaves
      que resulte na mesma árvore `T`.

   3. Suponha que após a inserção de todas as chaves, são
      removidos os nós contendo as chaves `25` e `18`.
      Desenhe a árvore resultante.

4. Escreva (em pseudo-código ou C/C++) os procedimentos 
   `minimo` e `maximo` que recebem o nó raiz de uma
   árvore binária de busca `T` e devolvem o menor elemento
   e o maior elemento entre as chaves armazenadas em `T`.
   Você pode supor que as chaves sejam números inteiros.

5. Escreva (em pseudo-código ou C/C++) os procedimentos
   `antecessor` e `sucessor` que recebem: o nó raiz
   de uma árvore binária de busca `T` e um no `x` de `T`;
   os procedimentos calculam o antecessor e o sucessor,
   respectivamente, da chave contida no nó `x`. Você pode
   supor que as chaves sejam números inteiros.

6. Usando chamadas para `minimo` e `sucessor`, escreva um
   procedimento para encontrar o quinto menor elemento
   de uma árvore `T` (para simplificar, você pode supor
   que a árvore sempre tem pelo menos 5 elementos).
   Analise a complexidade do seu procedimento em função
   da altura da árvore binária de busca.

7. Considere uma árvore binária AVL inicialmente vazia.
   Sabendo que as chaves são números naturais inseridos
   na seguinte ordem: `{7, 4, 5, 10, 13, 1, 15}`

   1. Desenhe a árvore `T` resultante.

   2. Para cada chave inserida, registre qual tipo de
      rotação (RR, LL, LR, RL) foi usada para balancear
      a árvore.

8. Seja `T` uma árvore rubro-negra válida. Usando pseudo-código
   ou C/C++, escreva um procedimento que recebe a raiz da
   árvore e devolve a *altura negra* da árvore. Determine
   a complexidade assintótica do seu procedimento (em
   função do número de elementos da árvore).