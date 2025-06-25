#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pedido.h"

typedef struct celula Celula;

struct celula
{
    void *comida;
    char tipo;
    Celula *prox;
};

struct pedido
{
    int numero;
    Celula *primCaloricas, *ultCaloricas;
    Celula *primMagras, *ultMagras;
};

Pedido *inicPedido(int numero)
{
    Pedido *pedido = (Pedido *)malloc(sizeof(Pedido));
    pedido->numero = numero;
    pedido->primCaloricas = pedido->ultCaloricas = pedido->primMagras = pedido->ultMagras = NULL;
    return pedido;
}

void insereComidaVegana(Pedido *pedido, ComidaVegana *food)
{
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->comida = food;
    nova->tipo = 'V';
    nova->prox = NULL;

    if (retornaCaloriasComidaVegana(food) > 500)
    {
        if (pedido->primCaloricas == NULL)
        {
            pedido->primCaloricas = nova;
            pedido->ultCaloricas = nova;
        }
        else
        {
            pedido->ultCaloricas->prox = nova;
            pedido->ultCaloricas = nova;
        }
    }
    else
    {
        if (pedido->primMagras == NULL)
        {
            pedido->primMagras = nova;
            pedido->ultMagras = nova;
        }
        else
        {
            pedido->ultMagras->prox = nova;
            pedido->ultMagras = nova;
        }
    }
}

void insereComidaNaoVegana(Pedido *pedido, ComidaNaoVegana *food)
{
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->comida = food;
    nova->tipo = 'N';
    nova->prox = NULL;

    if (retornaCaloriasComidaVegana(food) > 500)
    {
        if (pedido->primCaloricas == NULL)
        {
            pedido->primCaloricas = nova;
            pedido->ultCaloricas = nova;
        }
        else
        {
            pedido->ultCaloricas->prox = nova;
            pedido->ultCaloricas = nova;
        }
    }
    else
    {
        if (pedido->primMagras == NULL)
        {
            pedido->primMagras = nova;
            pedido->ultMagras = nova;
        }
        else
        {
            pedido->ultMagras->prox = nova;
            pedido->ultMagras = nova;
        }
    }
}

int retornaNumeroPedido(Pedido *pedido)
{
    return pedido->numero;
}

void atualizaSituacaoComidaNaoVegana(Pedido *pedido, ComidaNaoVegana *food)
{
    return;
}

void atualizaSituacaoComidaVegana(Pedido *pedido, ComidaVegana *food)
{
    return;
}

void imprimePedido(Pedido *pedido)
{
    printf("\nImprimindo Detalhes do Pedido numero: %d\n", pedido->numero);
    printf("Valor total do Pedido: %.2f\n", calculaValorPedido(pedido));

    int totalCaloricas = 0;
    for (Celula *i = pedido->primCaloricas; i != NULL; i = i->prox)
    {
        totalCaloricas++;
    }

    int totalMagras = 0;
    for (Celula *i = pedido->primMagras; i != NULL; i = i->prox)
    {
        totalMagras++;
    }

    printf("\nLista de Itens de Baixa Caloria: %d\n", totalMagras);
    for (Celula *i = pedido->primMagras; i != NULL; i = i->prox)
    {
        if (i->tipo == 'V')
        {
            ComidaVegana *v = (ComidaVegana *)i->comida;
            printf("Nome comida vegana: %s, calorias: %d\n", retornaNomeComidaVegana(v), retornaCaloriasComidaVegana(v));
        }
        else
        {
            ComidaNaoVegana *n = (ComidaNaoVegana *)i->comida;
            printf("Nome comida nao vegana: %s, valor: %.2f, calorias: %d\n", retornaNomeComidaNaoVegana(n), retornaValorComidaNaoVegana(n), retornaCaloriasComidaNaoVegana(n));
        }
    }

    printf("\nLista de Itens de Alta Caloria: %d\n", totalCaloricas);
    for (Celula *i = pedido->primCaloricas; i != NULL; i = i->prox)
    {
        if (i->tipo == 'V')
        {
            ComidaVegana *v = (ComidaVegana *)i->comida;
            printf("Nome comida vegana: %s, calorias: %d\n", retornaNomeComidaVegana(v), retornaCaloriasComidaVegana(v));
        }
        else
        {
            ComidaNaoVegana *n = (ComidaNaoVegana *)i->comida;
            printf("Nome comida nao vegana: %s, valor: %.2f, calorias: %d\n", retornaNomeComidaNaoVegana(n), retornaValorComidaNaoVegana(n), retornaCaloriasComidaNaoVegana(n));
        }
    }
}

float calculaValorPedido(Pedido *pedido)
{
    float valor = 0;

    for (Celula *i = pedido->primMagras; i != NULL; i = i->prox)
    {
        if (i->tipo == 'V')
        {
            valor += 30;
        }
        else
        {
            ComidaNaoVegana *n = (ComidaNaoVegana *)i->comida;
            valor += retornaValorComidaNaoVegana(n);
        }
    }

    for (Celula *i = pedido->primCaloricas; i != NULL; i = i->prox)
    {
        if (i->tipo == 'V')
        {
            valor += 30;
        }
        else
        {
            ComidaNaoVegana *n = (ComidaNaoVegana *)i->comida;
            valor += retornaValorComidaNaoVegana(n);
        }
    }

    return valor;
}

void liberaPedido(Pedido *pedido)
{
    Celula *prox = NULL;
    Celula *i = pedido->primCaloricas;

    while (i != NULL)
    {
        prox = i->prox;
        free(i);
        i = prox;
    }

    prox = NULL;
    i = pedido->primMagras;

    while (i != NULL)
    {
        prox = i->prox;
        free(i);
        i = prox;
    }

    free(pedido);
}