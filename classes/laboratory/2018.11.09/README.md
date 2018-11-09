# Árvore de Prefixo (*Trie*)
*Retirado do roteiro de aula do Prof. Carlos da Silva dos Santos, CMCC/UFABC.*

Nessa aula você vai implementar um programa para imprimir
sugestões de "autocompletar" para URLs. Para isso, vamos
usar uma implementação de árvore de prefixo (*trie*).

1. Estude a implementação da *trie* que foi fornecida.
2. Você deve criar uma função `tn_suggest` com a seguinte assinatura:
   
   ```c++
   void tn_suggest (tn_trie_node* root, string query);
   ```

   em que `root` representa a raiz de uma árvore e `query`
   é um prefixo de uma URL para a qual queremos sugerir
   possibilidades de completar. A sua função deve ter o
   seguinte comportamento:
   
   1. Caso `query` seja uma palavra já armazenada na árvore,
      sua função deve imprimir `query` e terminar.
   2. Caso `query` **não seja** prefixo de nenhuma palavra
      armazenada na árvore, sua função não deve imprimir
      nada, terminando imediatamente.
   3. Caso `query` seja prefixo de pelo menos uma palavra
      armazenada na árvore, sua função deve imprimir todas
      as palavras que tem `query` como prefixo, em ordem
      lexicográfica (ordem de dicionário).
3. Elabore um programa que constrói uma *trie* a partir da
   lista de URLs fornecida. Em seguida, o programa deve
   pedir ao usuário que digite uma URL (ou o início de uma).
   O programa deve então imprimir todas as sugestões possíveis
   para completar a `string` enviada pelo usuário.
