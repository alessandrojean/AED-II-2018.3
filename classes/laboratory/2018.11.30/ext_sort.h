#ifndef __EXT_SORT_H__
#define __EXT_SORT_H__

#include <stdio.h>
#include <string.h>
#include "util.h"

/**
 * Faz a intercalação entre dois subarrays contíguos ordenados.
 * Primeiro array: buffer[left..median - 1]
 * Segundo array: buffer[median..right - 1]
 *
 * Ao final da execução, o conteúdo ordenado estará guardado
 * em buffer[left..right - 1].
 * 
 * @param buffer buffer de entrada.
 * @param left índice inicial.
 * @param median índice separador.
 * @param right índice final.
 */
void merge(int* buffer, int left, int median, int right);

/**
 * Aplica o algoritmo MergeSort aos elementos de buffer
 * que estejam nas posições left até (right - 1).
 *
 * Para ordenar um buffer inteiro, chamar com o seguintes
 * parametros:
 *
 * merge_sort(buffer, 0, BUFFER_LENGTH)
 *
 * em que BUFFER_LENGTH é o número de elementos 
 * guardados em buffer.
 * 
 * @param buffer buffer de entrada.
 * @param left índice inicial.
 * @param right índice final.
 */
void merge_sort(int* buffer, int left, int right);

/**
 * Escreve o conteúdo de buffer no arquivo de saída.
 * 
 * @param output arquivo de saída.
 * @param buffer buffer que será lido.
 * @param num_items quantidade de elementos de buffer.
 * @return número de elementos.
 */
int write_buffer(FILE* output, int* buffer, int num_items);

/**
 * Executa os runs no arquivo de entrada.
 * 
 * @param input_file arquivo que será lido.
 * @param page_size tamanho da página, em número de itens.
 * @return número de páginas.
 */
int create_runs(char* input_file, int page_size);

/**
 * Lê o conteúdo de um arquivo já aberto em um buffer.
 * 
 * @param input arquivo de leitura.
 * @param buffer buffer de destino.
 * @param n número de elementos que serão lidos.
 * @param has_data se dados foram lidos do arquivo.
 * @return quantidade de elementos lidos.
 */
int read_file(FILE* input, int* buffer, int n, int* has_data);

/**
 * Essa função intercala o conteúdo de dois arquivos ordenados,
 * produzindo um arquivo de saída ordenado que contém a união dos
 * conteúdos dos arquivos de entrada.
 * 
 * Cada arquivo de entrada contém um número inteiro por linha.
 * Ambos arquivos de entrada devem estar ordenados.
 * 
 * @param output nome do arquivo de saída que será criado.
 * @param input1 nome do primeiro arquivo de entrada.
 * @param input2 nome do segundo arquivo de entrada.
 * @param page_size tamanho da página, em número de itens.
 */
void merge_files(char* output, char* input1, char* input2, int page_size);

#endif // __EXT_SORT_H__
