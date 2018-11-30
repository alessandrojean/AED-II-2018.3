#ifndef __UTIL_H__
#define __UTIL_H__

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Abre um arquivo e retorna o ponteiro.
 *
 * @param file_name nome do arquivo.
 * @param mode modo de abertura.
 * @return ponteiro para o arquivo, caso
 * não haja nenhum erro.
 */
FILE* open_file(char* file_name, char* mode);

#endif  // __UTIL_H__
