#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

struct hash
{
    int qtd, tamTabela;
    Palavra **palavras;
};

Hash *criaHash(int tamTabela)
{
    Hash *hash = (Hash *)malloc(sizeof(Hash));
    hash->tamTabela = tamTabela;
    hash->qtd = 0;
    hash->palavras = (Palavra **)malloc(tamTabela * sizeof(Palavra *));
    for (int i = 0; i < hash->tamTabela; i++)
    {
        hash->palavras[i] = NULL;
    }
    return hash;
}

void liberaHash(Hash *hash)
{
    if (hash != NULL)
    {
        for (int i = 0; i < hash->tamTabela; i++)
        {
            if (hash->palavras[i] != NULL)
            {
                liberaPalavra(hash->palavras[i]);
            }
        }
        free(hash->palavras);
        free(hash);
    }
}

int valorTexto(char *texto)
{
    int valor = 7;
    int tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++)
    {
        valor = 31 * valor + (int)texto[i];
    }
    return valor;
}

int chaveHash(char *texto, int tamTabela)
{
    int chave = valorTexto(texto);
    if (chave < 0)
    {
        chave *= (-1);
    }
    return chave % tamTabela;
}

void inserePalavraHash(Hash *hash, char *texto)
{
    int posicao = chaveHash(texto, hash->tamTabela);

    while (hash->palavras[posicao] != NULL)
    {
        if (!strcmp(getTexto(hash->palavras[posicao]), texto))
        {
            incrementaFrequencia(hash->palavras[posicao]);
            return;
        }

        posicao = (posicao++) % hash->tamTabela;
    }

    hash->palavras[posicao] = criaPalavra(texto);
    hash->qtd++;
}

int getTotalPalavras(Hash *hash)
{
    int total = 0;
    for (int i = 0; i < hash->tamTabela; i++)
    {
        if (hash->palavras[i] != NULL)
        {
            total += getFrequencia(hash->palavras[i]);
        }
    }
    return total;
}

int getQtdPalavrasDistintas(Hash *hash)
{
    return hash->qtd;
}

Palavra *getPalavraMaisFrequente(Hash *hash)
{
    Palavra *maisFrequente = NULL;
    int frequenciaMax = 0;

    for (int i = 0; i < hash->tamTabela; i++)
    {
        if (hash->palavras[i] != NULL)
        {
            if (getFrequencia(hash->palavras[i]) > frequenciaMax)
            {
                frequenciaMax = getFrequencia(hash->palavras[i]);
                maisFrequente = hash->palavras[i];
            }
        }
    }
    return maisFrequente;
}

void preencheVetorPalavras(Hash *hash, Palavra **vetor)
{
    int j = 0;
    for (int i = 0; i < hash->tamTabela; i++)
    {
        if (hash->palavras[i] != NULL)
        {
            vetor[j] = hash->palavras[i];
            j++;
        }
    }
}