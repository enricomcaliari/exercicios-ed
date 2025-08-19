#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

typedef struct celula Celula;

struct celula
{
    Pais *pais;
    Celula *prox;
};

struct hash
{
    Celula **tabela;
    int tamanho;
};

Hash *criaHash(int tamanho)
{
    Hash *hash = (Hash *)malloc(sizeof(Hash));
    hash->tamanho = tamanho;
    hash->tabela = (Celula **)malloc(tamanho * sizeof(Celula *));
    for (int i = 0; i < hash->tamanho; i++)
    {
        hash->tabela[i] = NULL;
    }
    return hash;
}

int valorString(char *string)
{
    int valor = 7;
    for (int i = 0; i < strlen(string); i++)
    {
        valor = 31 * valor + (int)string[i];
    }
    return valor;
}

int chaveHash(char *string, int tamanho)
{
    int chave = valorString(string);
    if (chave < 0)
    {
        chave *= (-1);
    }
    return chave % tamanho;
}

Celula *buscaPaisLista(Celula *celula, char *nome)
{
    Celula *p = celula;
    while (p != NULL && strcmp(retornaNomePais(p->pais), nome) != 0)
    {
        p = p->prox;
    }
    return p;
}

void insereAtualizaPais(Hash *hash, char *nome, int ouro, int prata, int bronze, int total)
{
    int indice = chaveHash(nome, hash->tamanho);

    Celula *celula = buscaPaisLista(hash->tabela[indice], nome);

    if (celula != NULL)
    {
        incrementaOuroPais(celula->pais, ouro);
        incrementaPrataPais(celula->pais, prata);
        incrementaBronzePais(celula->pais, bronze);
    }
    else
    {
        Pais *novoPais = criaPais(nome, ouro, prata, bronze, total);
        Celula *novaCelula = (Celula *)malloc(sizeof(Celula));
        novaCelula->pais = novoPais;
        novaCelula->prox = hash->tabela[indice];
        hash->tabela[indice] = novaCelula;
    }
}

int preencheVetorPaises(Hash *hash, Pais **vetor)
{
    int contador = 0;
    for (int i = 0; i < hash->tamanho; i++)
    {
        Celula *p = hash->tabela[i];
        while (p != NULL)
        {
            vetor[contador] = p->pais;
            contador++;
            p = p->prox;
        }
    }
    return contador;
}

int contaPaises(Hash *hash)
{
    int contador = 0;
    for (int i = 0; i < hash->tamanho; i++)
    {
        Celula *p = hash->tabela[i];
        while (p != NULL)
        {
            contador++;
            p = p->prox;
        }
    }
    return contador;
}

void liberaHash(Hash *hash)
{
    for (int i = 0; i < hash->tamanho; i++)
    {
        Celula *p = hash->tabela[i];
        while (p != NULL)
        {
            Celula *temp = p;
            p = p->prox;
            liberaPais(temp->pais);
            free(temp);
        }
    }
    free(hash->tabela);
    free(hash);
}