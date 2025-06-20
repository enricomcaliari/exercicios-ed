#ifndef _ESTOQUE_H
#define _ESTOQUE_H

#include "produto.h"

#define QTD_INICIAL_PRODUTOS 2

typedef struct Estoque Estoque;

Estoque *criaEstoque();

void *adicionaProdutoEstoque(Estoque *e, Produto *p);

void calculaValorEstoque(Estoque *e);

float getValorEstoque(Estoque *e);

void imprimeEstoque(Estoque *e);

void liberaEstoque(Estoque *e);

#endif