# Ordenação em memória externa
*Retirado do roteiro de aula do Prof. Carlos da Silva dos Santos, CMCC/UFABC.*

Nessa aula estudaremos o problema de ordenação usando 
memória externa.

1. Estude o código que foi fornecido.
2. Você deve implementar a função `merge_files`, conforme a
   assinatura e descrição abaixo:

   ```c
   /**
    * Essa função intercala o conteúdo de dois arquivos ordenados,
    * produzindo um arquivo de saída ordenado que contém a união dos
    * conteúdos dos arquivos de entrada.
    *
    * Cada arquivo de entrada contém um número inteiro por linha.
    * Ambos arquivos de entrada devem estar ordenados.
    *
    * Entrada:
    * output: nome do arquivo de saída que será criado.
    * input1: nome do primeiro arquivo de entrada.
    * input2: nome do segundo arquivo de entrada.
    * page_size: tamanho da página, em número de itens.
    */
   void merge_files(char* output, char* input1, char* input2, int page_size);
   ```
