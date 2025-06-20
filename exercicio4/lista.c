#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct celula Celula;

struct celula
{
    Produto *produto;
    Celula *prox;
};

struct lista
{
    Celula *prim, *ult;
};

Lista *criaLista()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->prim = NULL;
    l->ult = NULL;
    return l;
}

void insereProdutoLista(Lista *l, Produto *p)
{
    Celula *aux;
    for (aux = l->prim; aux != NULL; aux = aux->prox)
    {
        if (getCodigoProduto(aux->produto) == getCodigoProduto(p))
        {
            printf("\nCodigo ja cadastrado\n");
            liberaProduto(p);
            return;
        }
    }

    Celula *nova = (Celula *)malloc(sizeof(Celula));

    if (l->ult == NULL)
    {
        l->prim = nova;
        l->ult = nova;
    }
    else
    {
        l->ult->prox = nova;
        l->ult = nova;
    }

    l->ult->produto = p;
    l->ult->prox = NULL;
}

void retiraProdutoLista(Lista *l, int codigo)
{
    Celula *ant = NULL;
    Celula *p = l->prim;

    while (p != NULL && getCodigoProduto(p->produto) != codigo)
    {
        ant = p;
        p = p->prox;
    }

    if (p == NULL)
    {
        printf("\nLista vazia\n");
        return;
    }

    if (p == l->prim && p == l->ult)
    {
        l->prim = NULL;
        l->ult = NULL;
        liberaProduto(p->produto);
        free(p);
        printf("\nProduto removido com sucesso\n");
        return;
    }

    if (p == l->prim)
    {
        l->prim = p->prox;
    }
    else
    {
        ant->prox = p->prox;
    }

    liberaProduto(p->produto);
    free(p);

    printf("\nProduto removido com sucesso\n");
}

void imprimeLista(Lista *l)
{
    if (l->prim == NULL && l->ult == NULL)
    {
        printf("\nLista vazia\n");
    }
    else
    {
        printf("\nLista:\n");

        Celula *aux;

        for (aux = l->prim; aux != NULL; aux = aux->prox)
        {
            imprimeProduto(aux->produto);
        }
    }
}

void liberaLista(Lista *l)
{
    Celula *prox = NULL;
    Celula *p = l->prim;

    while (p != NULL)
    {
        prox = p->prox;
        liberaProduto(p->produto);
        free(p);
        p = prox;
    }

    free(l);
}