#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

struct Produto
{
    char *nome;
    float valor;
    int quantidade;
};

Produto *criaProduto(char *nome, float valor, int quantidade)
{
    Produto *p = (Produto *)malloc(sizeof(Produto));
    p->nome = (char *)malloc(MAX_NOME_PRODUTO * sizeof(char));
    strcpy(p->nome, nome);
    p->valor = valor;
    p->quantidade = quantidade;
    return p;
}

Produto *leProduto()
{
    char nome[MAX_NOME_PRODUTO];
    float valor;
    int quantidade;

    printf("\nDigite o nome do produto:\n");
    scanf("%49[^\n]\n", nome);

    printf("\nDigite o valor do produto:\n");
    scanf("%f\n", &valor);

    printf("\nDigite a quantidade do produto:\n");
    scanf("%d\n", &quantidade);

    Produto *p = criaProduto(nome, valor, quantidade);

    return p;
}

char *getNomeProduto(Produto *p)
{
    return p->nome;
}

float getValorProduto(Produto *p)
{
    return p->valor;
}

int getQuantidadeProduto(Produto *p)
{
    return p->quantidade;
}

void imprimeProduto(Produto *p)
{
    printf("        Item: %s, valor unitario: %.2f, quantidade: %d\n", p->nome, p->valor, p->quantidade);
}

void liberaProduto(Produto *p)
{
    if (p != NULL)
    {
        free(p->nome);
        free(p);
    }
}