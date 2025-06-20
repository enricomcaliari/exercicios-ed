#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedido.h"

typedef struct celula Celula;

struct celula
{
    TProduto *produto;
    Celula *prox;
};

struct pedido
{
    char *dono;
    Celula *prim, *ult;
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
    Celula *aux;
    for (aux = pedido->prim; aux != NULL; aux = aux->prox)
    {
        if (!strcmp(RetornaNome(aux->produto), RetornaNome(prod)))
        {
            printf("Produto ja existe no pedido\n");
            DestroiProd(prod);
            return;
        }
    }

    Celula *nova = (Celula *)malloc(sizeof(Celula));

    if (pedido->prim == NULL && pedido->ult == NULL)
    {
        pedido->prim = nova;
        pedido->ult = nova;
    }
    else
    {
        pedido->ult->prox = nova;
        pedido->ult = nova;
    }

    pedido->ult->produto = prod;
    pedido->ult->prox = NULL;
}

void ImprimePedido(TPedido *pedido)
{
    printf("Cliente: %s\n", pedido->dono);

    if (pedido->prim == NULL && pedido->ult == NULL)
    {
        printf("Nao ha produtos nesse pedido!\n");
        return;
    }

    Celula *aux;
    for (aux = pedido->prim; aux != NULL; aux = aux->prox)
    {
        ImprimeIngredientes(aux->produto);
    }
}

void RetiraProdutoPedido(TPedido *pedido, char *prod)
{
    Celula *ant = NULL;
    Celula *aux = pedido->prim;

    while (aux != NULL && strcmp(RetornaNome(aux->produto), prod) != 0)
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
    }
    else
    {
        ant->prox = aux->prox;
    }

    free(aux);
}

int EnviaPedido(TPedido *pedido, int restricao_calorica, char *restricao_alimentar)
{
    Celula *aux;
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
    Celula *prox;
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