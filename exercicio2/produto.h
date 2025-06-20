#ifndef _PRODUTO_H
#define _PRODUTO_H

#define MAX_NOME_PRODUTO 50

typedef struct Produto Produto;

Produto *criaProduto(char *nome, float valor, int quantidade);

Produto *leProduto();

char *getNomeProduto(Produto *p);

float getValorProduto(Produto *p);

int getQuantidadeProduto(Produto *p);

void imprimeProduto(Produto *p);

void liberaProduto(Produto *p);

#endif