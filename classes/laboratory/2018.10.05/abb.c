#include "abb.h"

void erd (no *r) {
  if (r != NULL) {
    erd(r->esq);
    printf("%d ", r->conteudo);
    erd(r->dir);
  }
}

void imprimir_folhas (no *r) {
  if (r != NULL) {
    imprimir_folhas(r->esq);
    if ((r->esq == NULL) && (r->dir == NULL))
      printf("%d ", r->conteudo);
    imprimir_folhas(r->dir);
  }
}

int altura (no *r) {
  if (r == NULL)
    return -1;
  else {
    int he = altura(r->esq);
    int hd = altura(r->dir);
    if (he < hd)
      return hd + 1;
    else
      return he + 1;
  }
}

no* primeiro_erd (no *r) {
  while (r->esq != NULL)
    r = r->esq;
  return r;
}

no* ultimo_erd (no *r) {
  while (r->dir != NULL)
    r = r->dir;
  return r;
}

void preenche_filhos_pai (no *r) {
  if (r == NULL)
    return;

  if (r->dir != NULL) {
    r->dir->pai = r;
    preenche_filhos_pai(r->dir);
  }

  if (r->esq != NULL) {
    r->esq->pai = r;
    preenche_filhos_pai(r->esq);
  }
}

void preenche_pai (no *r) {
  if (r == NULL)
    return;

  r->pai = r;
  preenche_filhos_pai(r);
}

no* busca (no* r, int chave) {
  if (r == NULL || r->conteudo == chave)
    return r;
  if (r->conteudo > chave)
    return busca(r->esq, chave);
  else
    return busca(r->dir, chave);
}

no* inserir_no_na_arvore (no* r, int valor) {
  if (r == NULL) {
    no * novo = malloc(sizeof(no));
    if (novo != NULL) {
      novo->conteudo = valor;
      novo->esq = novo->dir = novo->pai = NULL;
    }
    return novo;
  }

  if (valor < r->conteudo) {
    no * resultado = inserir_no_na_arvore(r->esq, valor);
    if (resultado != NULL)
      r->esq = resultado;
  } else if (valor > r->conteudo) {
    no * resultado = inserir_no_na_arvore(r->dir, valor);
    if (resultado != NULL)
      r->dir = resultado;
  } else {
    return NULL;
  }

  return r;
}
