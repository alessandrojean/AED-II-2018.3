#ifndef _H_HASHING
#define _H_HASHING

/**
 * Gera um hash para a chave key,
 * utilizando o método da multiplicação.
 * 
 * @param key chave para gerar o hash
 * @param m número de posições da tabela
 * @param a constante não negativa, 0 < a < 1.
 * @return hash gerado
 */
int mul_hash (int key, int m, float a);

#endif
