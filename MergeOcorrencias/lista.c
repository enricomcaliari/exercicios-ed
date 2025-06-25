#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

typedef struct celula TCelula;

struct aluno
{
    char *nome;
    int matricula;
};

struct celula
{
    TAluno *aluno;
    TCelula *prox;
};

struct lista
{
    TCelula *prim, *ult;
};

TLista *CriaLista()
{
    TLista *lista = (TLista *)malloc(sizeof(TLista));
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}

TAluno *InicializaAluno(char *nome, int matricula)
{
    TAluno *aluno = (TAluno *)malloc(sizeof(TAluno));
    aluno->nome = strdup(nome);
    aluno->matricula = matricula;
    return aluno;
}

void InsereAluno(TLista *lista, TAluno *aluno)
{
    for (TCelula *i = lista->prim; i != NULL; i = i->prox)
    {
        if (i->aluno->matricula == aluno->matricula)
        {
            printf("\nAluno ja inserido na lista\n");
            return;
        }
    }

    TCelula *nova = (TCelula *)malloc(sizeof(TCelula));
    nova->aluno = aluno;
    nova->prox = lista->prim;
    lista->prim = nova;

    if (lista->ult == NULL)
    {
        lista->ult = nova;
    }
}

TAluno *Retira(TLista *lista, int mat)
{
    TCelula *ant = NULL;
    TCelula *i = lista->prim;

    while (i != NULL && i->aluno->matricula != mat)
    {
        ant = i;
        i = i->prox;
    }

    if (i == NULL)
    {
        return NULL;
    }

    if (lista->prim == i && lista->ult == i)
    {
        lista->prim = NULL;
        lista->ult = NULL;
        TAluno *aluno = i->aluno;
        free(i);
        return aluno;
    }

    if (lista->prim == i)
    {
        lista->prim = i->prox;
        TAluno *aluno = i->aluno;
        free(i);
        return aluno;
    }

    ant->prox = i->prox;
    TAluno *aluno = i->aluno;
    free(i);
    return aluno;
}

void RetiraRepetidos(TLista *lista)
{
    return;
}

TLista *Merge(TLista *turma1, TLista *turma2)
{
    TLista *merge = CriaLista();

    for (TCelula *i = turma1->prim; i != NULL; i = i->prox)
    {
        TAluno *aluno = InicializaAluno(i->aluno->nome, i->aluno->matricula);
        InsereAluno(merge, aluno);
    }
    
    for (TCelula *i = turma2->prim; i != NULL; i = i->prox)
    {
        TAluno *aluno = InicializaAluno(i->aluno->nome, i->aluno->matricula);
        InsereAluno(merge, aluno);
    }

    return merge;
}

void LiberaAluno(TAluno *aluno)
{
    free(aluno->nome);
    free(aluno);
}

void Imprime(TLista *lista)
{
    for (TCelula *i = lista->prim; i != NULL; i = i->prox)
    {
        printf("Aluno: %s, Matricula: %d\n", i->aluno->nome, i->aluno->matricula);
    }
}

void LiberaLista(TLista *lista)
{
    TCelula *prox = NULL;
    TCelula *i = lista->prim;

    while (i != NULL)
    {
        prox = i->prox;
        LiberaAluno(i->aluno);
        free(i);
        i = prox;
    }

    free(lista);
}