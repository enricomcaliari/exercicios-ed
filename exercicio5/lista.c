#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista
{
    Produto *produto;
    Lista *ant, *prox;
};

Lista *criaLista()
{
    return NULL;
}

Lista *insereProdutoLista(Lista *l, Produto *p)
{
    Lista *aux;
    for (aux = l; aux != NULL; aux = aux->prox)
    {
        if (getCodigoProduto(aux->produto) == getCodigoProduto(p))
        {
            printf("\nCodigo ja cadastrado\n");
            liberaProduto(p);
            return NULL;
        }
    }

    Lista *nova = (Lista *)malloc(sizeof(Lista));
    nova->produto = p;
    nova->ant = NULL;
    nova->prox = l;

    if (l != NULL)
    {
        l->ant = nova;
    }

    printf("\nProduto cadastrado com sucesso\n");

    return nova;
}

Lista *retiraProdutoLista(Lista *l, int codigo)
{
    Lista *p = NULL;
    for (Lista *aux = l; aux != NULL; aux = aux->prox)
    {
        if (getCodigoProduto(aux->produto) == codigo)
        {
            p = aux;
        }
    }

    if (p == NULL)
    {
        printf("\nProduto nao encontrado\n");
        return NULL;
    }

    if (p->ant != NULL)
    {
        p->ant->prox = p->prox;
    }
    else
    {
        l = p->prox;
        l->ant = NULL;
    }

    if (p->prox != NULL)
    {
        p->prox->ant = p->ant;
    }
    else
    {
        p->ant->prox = NULL;
    }

    liberaProduto(p->produto);
    free(p);
    printf("\nProduto removido com sucesso\n");

    return l;
}

void imprimeLista(Lista *l)
{
    if (l == NULL)
    {
        printf("\nLista vazia\n");
    }
    else
    {
        printf("\nLista:\n");

        for (Lista *aux; aux != NULL; aux = aux->prox)
        {
            imprimeProduto(aux->produto);
        }
    }
}

void liberaLista(Lista *l)
{
    Lista *aux = l;
    Lista *prox;

    while (aux != NULL)
    {
        prox = aux->prox;
        liberaProduto(aux->produto);
        free(aux);
        aux = prox;
    }
}