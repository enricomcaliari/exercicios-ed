#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedido.h"

typedef struct celula TCelula;

struct celula
{
    TProduto *produto;
    TCelula *prox;
};

struct pedido
{
    char *dono;
    TCelula *prim, *ult;
};

TPedido *InicPedido(char *dono)
{
    TPedido *pedido = (TPedido *)malloc(sizeof(TPedido));

    pedido->dono = strdup(dono);
    pedido->prim = NULL;
    pedido->ult = NULL;

    return pedido;
}

void IncluiProdutoPedido(TPedido *pedido, TProduto *prod)
{
    for (TCelula *aux = pedido->prim; aux != NULL; aux = aux->prox)
    {
        if (!strcmp(RetornaNome(aux->produto), RetornaNome(prod)))
        {
            printf("Produto já existe no pedido\n");
            DestroiProd(prod);
            return;
        }
    }

    TCelula *novo = (TCelula *)malloc(sizeof(TCelula));
    novo->produto = prod;

    if (pedido->prim == NULL)
    {
        pedido->prim = novo;
        pedido->ult = novo;
    }
    else
    {
        pedido->ult->prox = novo;
        pedido->ult = novo;
    }

    pedido->ult->prox = NULL;
}

void ImprimePedido(TPedido *pedido)
{
    printf("\nCliente: %s\n", pedido->dono);

    if (pedido->prim == NULL)
    {
        printf("Nao ha produtos neste pedido!\n");
        return;
    }
    else
    {
        for (TCelula *aux = pedido->prim; aux != NULL; aux = aux->prox)
        {
            ImprimeIngredientes(aux->produto);
        }
    }
}

void RetiraProdutoPedido(TPedido *pedido, char *prod)
{
    TCelula *ant = NULL;
    TCelula *aux = pedido->prim;

    while (aux != NULL && strcmp(RetornaNome(aux->produto), prod))
    {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == NULL)
    {
        return;
    }

    if (aux == pedido->prim && aux == pedido->ult)
    {
        pedido->prim = NULL;
        pedido->ult = NULL;
        free(aux);
        return;
    }

    if (aux == pedido->prim)
    {
        pedido->prim = aux->prox;
        free(aux);
        return;
    }

    ant->prox = aux->prox;
    free(aux);
}

int EnviaPedido(TPedido *pedido, int restricao_calorica, char *restricao_alimentar)
{
    TCelula *aux;
    int calorias = 0;

    for (aux = pedido->prim; aux != NULL; aux = aux->prox)
    {
        if (VerificaIngrediente(aux->produto, restricao_alimentar))
        {
            printf("Pedido nao Enviado! Restricao alimentar no produto: %s\n", RetornaNome(aux->produto));
            return 0;
        }
        calorias += Calorias(aux->produto);
    }

    if (calorias > restricao_calorica)
    {
        printf("Pedido nao Enviado! Pedido tem mais calorias do que a restricao, tente retirar algum produto!\n");
        return 0;
    }

    aux = pedido->prim;
    TCelula *prox;
    while (aux != NULL)
    {
        prox = aux->prox;
        free(aux);
        aux = prox;
    }

    free(pedido->dono);
    free(pedido);
    return 1;
}