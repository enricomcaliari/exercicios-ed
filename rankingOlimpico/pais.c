#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pais.h"

struct pais
{
    char *nome;
    int ouro, prata, bronze, total;
};

Pais *criaPais(char *nome, int ouro, int prata, int bronze, int total)
{
    Pais *pais = (Pais *)malloc(sizeof(Pais));
    pais->nome = strdup(nome);
    pais->ouro = ouro;
    pais->prata = prata;
    pais->bronze = bronze;
    pais->total = total;
    return pais;
}

void incrementaOuroPais(Pais *pais, int ouro)
{
    pais->ouro += ouro;
    pais->total += ouro;
}

void incrementaPrataPais(Pais *pais, int prata)
{
    pais->prata += prata;
    pais->total += prata;
}

void incrementaBronzePais(Pais *pais, int bronze)
{
    pais->bronze += bronze;
    pais->total += bronze;
}

char *retornaNomePais(Pais *pais)
{
    return pais->nome;
}

int retornaOuroPais(Pais *pais)
{
    return pais->ouro;
}

int retornaPrataPais(Pais *pais)
{
    return pais->prata;
}

int retornaBronzePais(Pais *pais)
{
    return pais->bronze;
}

void imprimePais(Pais *pais)
{
    if (pais != NULL)
    {
        printf("%s %d %d %d %d\n", pais->nome, pais->ouro, pais->prata, pais->bronze, pais->total);
    }
}

void liberaPais(Pais *pais)
{
    if (pais != NULL)
    {
        free(pais->nome);
        free(pais);
    }
}