#include <stdio.h>
#include <stdlib.h>
#include "estoque.h"

struct Estoque
{
    Produto **produto;
    int qtdProdutos;
    int qtdProdutosAlocados;
    float valor;
};

Estoque *criaEstoque()
{
    Estoque *e = (Estoque *)malloc(sizeof(Estoque));
    e->produto = (Produto **)malloc(QTD_INICIAL_PRODUTOS * sizeof(Produto *));
    e->qtdProdutosAlocados = QTD_INICIAL_PRODUTOS;
    e->qtdProdutos = 0;
    return e;
}

void *adicionaProdutoEstoque(Estoque *e, Produto *p)
{
    if (e->qtdProdutos == e->qtdProdutosAlocados)
    {
        e->qtdProdutosAlocados += QTD_INICIAL_PRODUTOS;
        e->produto = (Produto **)realloc(e->produto, e->qtdProdutosAlocados * sizeof(Produto *));
    }
    e->produto[e->qtdProdutos] = p;
    e->qtdProdutos++;
}

void calculaValorEstoque(Estoque *e)
{
    float valor = 0;
    for (int i = 0; i < e->qtdProdutos; i++)
    {
        valor += getQuantidadeProduto(e->produto[i]) * getValorProduto(e->produto[i]);
    }
    e->valor = valor;
}

float getValorEstoque(Estoque *e)
{
    return e->valor;
}

void imprimeEstoque(Estoque *e)
{
    printf("    Estoque: %.2f\n", e->valor);
    for (int i = 0; i < e->qtdProdutos; i++)
    {
        imprimeProduto(e->produto[i]);
    }
}

void liberaEstoque(Estoque *e)
{
    if (e != NULL)
    {
        for (int i = 0; i < e->qtdProdutos; i++)
        {
            liberaProduto(e->produto[i]);
        }
        free(e->produto);
        free(e);
    }
}