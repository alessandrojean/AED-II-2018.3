# Árvore Rubro-Negra (continuação)
*Retirado do roteiro de aula do Prof. Carlos da Silva dos Santos, CMCC/UFABC.*

Nessa aula você vai implementar o procedimento de inserção
na árvore rubro-negra. Para isso, vamos reaproveitar o
código que você já criou para as rotações.

Vamos nos basear na implementação apresentada na referência
*Introduction to Algorithms* (CLRS). O procedimento de inserção
será dividido em duas etapas: (i) inserção propriamente dita e
(ii) correção das propriedades da árvore que tenham sido
violadas.

Você deve criar uma função `rb_insert` com a seguinte assinatura:

```c
void rb_insert (Node ** T, int key);
```

A função deve se basear no seguinte pseudo-código (conforme
apresentado em CLRS):

```
RB-INSERT(T, z)
  y <- nil[T]
  x <- root[T]
  while x != nil[T]
    y <- x
    if key[z] < key[y]
      x <- left[x]
    else
      x <- right[x]
  p[z] <- y
  if y == nil[T]
    root[T] <- z
  else
    if key[z] < key[y]
      left[y] <- z
    else
      right[y] <- z
  left[z] <- nil[T]
  right[z] <- nil[T]
  color[z] <- RED
  RB-INSERT-FIXUP(T, z)
```

O procedimento termina com uma chamada para `RB-INSERT-FIXUP`,
que corrige eventuais violações das propriedades da árvore
rubro-negra. Note que o parâmetro `z` é um nó de árvore
para ser inserido, enquanto `rb_insert` recebe uma chave
inteira como argumento de entrada. No código acima, `left`,
`right` e `p` são operadores que devolvem nós vizinhos
esquerdo, direito e o pai de um nó, respectivamente. 
A constante `nil[T]` representa o valor de sentinela.

Para complementar a implementação, crie uma função 
`rb_insert_fixup`, baseando-se no pseudo-código a seguir:

```
RB-INSERT-FIXUP(T, z)
  while color[p[z]] == RED
    if p[z] == left[p[p[z]]]
      y <- right[p[p[z]]]
      // O tio (y) é vermelho
      if color[y] == RED
        color[p[z]] <- BLACK
        color[y] <- BLACK
        color[p[p[z]]] <- RED
        z <- p[p[z]]
      else
        if z == right[p[z]]
          z <- p[z]
          LEFT-ROTATE(T, z)
        color[p[z]] <- BLACK
        color[p[p[z]]] <- RED
        RIGHT-ROTATE(T, p[p[z]])
    else
      // Análogo às linhas 03-14, mas
      // invertendo esquerda e direita.
  color[root[T]] <- BLACK
```

Depois de implementar as duas funções, teste seu código
criando algumas árvores pequenas e verificando o resultado.

Crie agora uma função para calcular a altura de uma árvore
rubro-negra. Faça testes, variando o número de elementos
da árvore e medindo a altura obtida.
