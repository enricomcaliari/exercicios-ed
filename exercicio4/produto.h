#ifndef PRODUTO_H_
#define PRODUTO_H_

#include <stdio.h>

#define MAX_NOME_PRODUTO 50

typedef struct produto Produto;

Produto *criaProduto(char *nome, int codigo, float preco);

Produto *leProduto();

int getCodigoProduto(Produto *p);

void imprimeProduto(Produto *p);

void liberaProduto(Produto *p);

#endif