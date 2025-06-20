#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supermercado.h"

struct Supermercado
{
    char *nome;
    Filial **filial;
    int qtdFiliais;
    int qtdFiliaisAlocadas;
    int estoqueTotal;
};

Supermercado *criaSupermercado(char *nome)
{
    Supermercado *s = (Supermercado *)malloc(sizeof(Supermercado));
    s->nome = (char *)malloc(MAX_NOME_SUPERMERCADO * sizeof(char));
    s->filial = (Filial **)malloc(QTD_INICIAL_FILIAIS * sizeof(Filial *));

    strcpy(s->nome, nome);
    s->qtdFiliaisAlocadas = QTD_INICIAL_FILIAIS;
    s->qtdFiliais = 0;
    s->estoqueTotal = 0;
    return s;
}

Supermercado *leSupermercado()
{
    printf("\nDigite o nome do supermercado:\n");

    char nome[MAX_NOME_SUPERMERCADO];
    scanf("%49[^\n]\n", nome);

    Supermercado *s = criaSupermercado(nome);

    return s;
}

void *adicionaFilialSupermercado(Supermercado *s, Filial *f)
{
    if (s->qtdFiliais == s->qtdFiliaisAlocadas)
    {
        s->qtdFiliaisAlocadas += QTD_INICIAL_FILIAIS;
        s->filial = (Filial **)realloc(s->filial, s->qtdFiliaisAlocadas * sizeof(Filial *));
    }
    s->filial[s->qtdFiliais] = f;
    s->qtdFiliais++;
}

void calculaEstoqueTotalSupermercado(Supermercado *s)
{
    for (int i = 0; i < getQtdFiliaisSupermercado(s); i++)
    {
        calculaValorEstoque(getEstoqueFilial(getFilialSupermercado(s, i)));
    }
    int estoqueTotal = 0;
    for (int i = 0; i < s->qtdFiliais; i++)
    {
        estoqueTotal += getValorEstoque(getEstoqueFilial(s->filial[i]));
    }
    s->estoqueTotal = estoqueTotal;
}

float getEstoqueTotalSupermercado(Supermercado *s)
{
    return s->estoqueTotal;
}

int getQtdFiliaisSupermercado(Supermercado *s)
{
    return s->qtdFiliais;
}

Filial *getFilialSupermercado(Supermercado *s, int i)
{
    return s->filial[i];
}

void imprimeSupermercado(Supermercado *s)
{
    printf("\nNome: %s, Estoque Total: %d\n", s->nome, s->estoqueTotal);
    for (int i = 0; i < s->qtdFiliais; i++)
    {
        imprimeFilial(s->filial[i]);
    }
}

void liberaSupermercado(Supermercado *s)
{
    if (s != NULL)
    {
        free(s->nome);
        for (int i = 0; i < s->qtdFiliais; i++)
        {
            liberaFilial(s->filial[i]);
        }
        free(s->filial);
        free(s);
    }
}