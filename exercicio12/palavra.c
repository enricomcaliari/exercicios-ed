#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palavra.h"

struct palavra
{
    char *texto;
    int frequencia;
};

Palavra *criaPalavra(char *texto)
{
    Palavra *p = (Palavra *)malloc(sizeof(Palavra));
    p->texto = strdup(texto);
    p->frequencia = 1;
    return p;
}

void liberaPalavra(Palavra *p)
{
    if (p != NULL)
    {
        free(p->texto);
        free(p);
    }
}

void incrementaFrequencia(Palavra *p)
{
    if (p != NULL)
    {
        p->frequencia++;
    }
}

int getFrequencia(Palavra *p)
{
    if (p != NULL)
    {
        return p->frequencia;
    }
    return 0;
}

char *getTexto(Palavra *p)
{
    if (p != NULL)
    {
        return p->texto;
    }
    return NULL;
}

int comparaPalavras(Palavra *p1, Palavra *p2)
{
    return strcmp(p1->texto, p2->texto);
}