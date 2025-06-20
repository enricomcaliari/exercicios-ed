#ifndef _LISTA_H
#define _LISTA_H

#include "produto.h"

typedef struct lista Lista;

Lista *criaLista();

void insereProdutoLista(Lista *l, Produto *p);

void retiraProdutoLista(Lista *l, int codigo);

void imprimeLista(Lista *l);

void liberaLista(Lista *l);

#endif