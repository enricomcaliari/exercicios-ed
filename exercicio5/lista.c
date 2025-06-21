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
    Lista *aux = l;
    for (aux = l; aux != NULL; aux = aux->prox)
    {
        if (getCodigoProduto(aux->produto) == getCodigoProduto(p))
        {
            printf("\nCodigo ja cadastrado\n");
            liberaProduto(p);
            return l;
        }
    }

    if (l == NULL)
    {
        l = (Lista *)malloc(sizeof(Lista));
        l->produto = p;
        l->ant = NULL;
        l->prox = NULL;
        return l;
    }

    Lista *nova = (Lista *)malloc(sizeof(Lista));
    nova->produto = p;
    nova->prox = l;
    nova->ant = NULL;
    l->ant = nova;

    printf("\nProduto cadastrado com sucesso\n");

    return nova;
}

Lista *retiraProdutoLista(Lista *l, int codigo)
{
    if (getCodigoProduto(l->produto) == codigo && l->ant == NULL && l->prox == NULL)
    {
        liberaProduto(l->produto);
        free(l);
        return NULL;
    }

    if (getCodigoProduto(l->produto) == codigo)
    {
        Lista *temp = l->prox;
        liberaProduto(l->produto);
        free(l);
        temp->ant = NULL;
        return temp;
    }

    for (Lista *aux = l; aux != NULL; aux = aux->prox)
    {
        if (getCodigoProduto(aux->produto) == codigo)
        {
            if (aux->prox == NULL)
            {
                Lista *temp = aux->ant;
                liberaProduto(aux->produto);
                free(aux);
                temp->prox = NULL;
                return l;
            }
            Lista *tempAnt = aux->ant;
            Lista *tempProx = aux->prox;

            liberaProduto(aux->produto);
            free(aux);
            tempAnt->prox = tempProx;
            tempProx->ant = tempAnt;

            return l;
        }
    }

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

        for (Lista *aux = l; aux != NULL; aux = aux->prox)
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