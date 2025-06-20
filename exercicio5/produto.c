#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

struct produto
{
    char *nome;
    int codigo;
    float preco;
};

Produto *criaProduto(char *nome, int codigo, float preco)
{
    Produto *p = (Produto *)malloc(sizeof(Produto));
    p->nome = strdup(nome);
    p->codigo = codigo;
    p->preco = preco;

    return p;
}

Produto *leProduto()
{
    char nome[MAX_NOME_PRODUTO];
    int codigo;
    float preco;

    printf("\nDigite o nome do produto: ");
    scanf("%s", nome);

    printf("\nDigite o codigo do produto: ");
    scanf("%d", &codigo);

    printf("\nDigite o preco do produto: ");
    scanf("%f", &preco);

    Produto *p = criaProduto(nome, codigo, preco);

    return p;
}

int getCodigoProduto(Produto *p)
{
    return p->codigo;
}

void imprimeProduto(Produto *p)
{
    printf("\nProduto: %s\n", p->nome);
    printf("Codigo: %d\n", p->codigo);
    printf("Preco: R$%.2f\n", p->preco);
}

void liberaProduto(Produto *p)
{
    if (p != NULL)
    {
        free(p->nome);
        free(p);
    }
}