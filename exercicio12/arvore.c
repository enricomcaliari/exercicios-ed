#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

struct arvore
{
    Palavra *palavra;
    Arvore *esquerda;
    Arvore *direita;
};

Arvore *criaArvoreVazia()
{
    return NULL;
}

Arvore *inserePalavra(Arvore *a, char *texto)
{
    if (a == NULL)
    {
        a = (Arvore *)malloc(sizeof(Arvore));
        a->palavra = criaPalavra(texto);
        a->esquerda = NULL;
        a->direita = NULL;
    }
    else if (strcmp(texto, getTexto(a->palavra)) < 0)
    {
        a->esquerda = inserePalavra(a->esquerda, texto);
    }
    else if (strcmp(texto, getTexto(a->palavra)) > 0)
    {
        a->direita = inserePalavra(a->direita, texto);
    }
    else
    {
        incrementaFrequencia(a->palavra);
    }
    return a;
}

void liberaArvore(Arvore *a)
{
    if (a != NULL)
    {
        liberaArvore(a->esquerda);
        liberaArvore(a->direita);
        liberaPalavra(a->palavra);
        free(a);
    }
}

int contaPalavrasDistintas(Arvore *a)
{
    if (a == NULL)
    {
        return 0;
    }
    return 1 + contaPalavrasDistintas(a->esquerda) + contaPalavrasDistintas(a->direita);
}

int contaTotalPalavras(Arvore *a)
{
    if (a == NULL)
    {
        return 0;
    }
    return getFrequencia(a->palavra) + contaTotalPalavras(a->esquerda) + contaTotalPalavras(a->direita);
}

Palavra *encontraMaisFrequente(Arvore *a)
{
    Palavra *maisFrequente = NULL;

    if (a == NULL)
    {
        return NULL;
    }

    Palavra *maisFrequenteEsq = encontraMaisFrequente(a->esquerda);
    Palavra *maisFrequenteDir = encontraMaisFrequente(a->direita);
    Palavra *maisFrequenteAtual = a->palavra;

    if (maisFrequenteEsq != NULL && getFrequencia(maisFrequenteEsq) > getFrequencia(maisFrequenteAtual))
    {
        maisFrequenteAtual = maisFrequenteEsq;
    }

    if (maisFrequenteDir != NULL && getFrequencia(maisFrequenteDir) > getFrequencia(maisFrequenteAtual))
    {
        maisFrequenteAtual = maisFrequenteDir;
    }

    return maisFrequenteAtual;
}

Arvore *getArvoreDireita(Arvore *a)
{
    if (a == NULL)
    {
        return NULL;
    }
    return a->direita;
}

Arvore *getArvoreEsquerda(Arvore *a)
{
    if (a == NULL)
    {
        return NULL;
    }
    return a->esquerda;
}

Palavra *getPalavra(Arvore *a)
{
    if (a == NULL)
    {
        return NULL;
    }
    return a->palavra;
}