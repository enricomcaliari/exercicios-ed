#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

struct arvore
{
    Aluno *aluno;
    Arvore *esquerda;
    Arvore *direita;
};

Arvore *criaArvore()
{
    return NULL;
}

Arvore *insereAlunoArvore(Arvore *arvore, Aluno *aluno)
{
    if (arvore == NULL)
    {
        arvore = (Arvore *)malloc(sizeof(Arvore));
        arvore->aluno = aluno;
        arvore->esquerda = NULL;
        arvore->direita = NULL;
        return arvore;
    }
    else if (strcmp(retornaNomeAluno(aluno), retornaNomeAluno(arvore->aluno)) < 0)
    {
        arvore->esquerda = insereAlunoArvore(arvore->esquerda, aluno);
    }
    else if (strcmp(retornaNomeAluno(aluno), retornaNomeAluno(arvore->aluno)) > 0)
    {
        arvore->direita = insereAlunoArvore(arvore->direita, aluno);
    }

    return arvore;
}

Aluno *buscaAlunoArvore(Arvore *arvore, char *nome)
{
    if (arvore == NULL)
    {
        return NULL;
    }

    if (!strcmp(nome, retornaNomeAluno(arvore->aluno)))
    {
        return arvore->aluno;
    }
    else if (strcmp(nome, retornaNomeAluno(arvore->aluno)) < 0)
    {
        return buscaAlunoArvore(arvore->esquerda, nome);
    }
    else
    {
        return buscaAlunoArvore(arvore->direita, nome);
    }
}

void imprimeArvore(Arvore *arvore)
{
    if (arvore != NULL)
    {
        imprimeArvore(arvore->esquerda);
        imprimeAluno(arvore->aluno);
        imprimeArvore(arvore->direita);
    }
}

void liberaArvore(Arvore *arvore)
{
    if (arvore != NULL)
    {
        liberaArvore(arvore->esquerda);
        liberaArvore(arvore->direita);
        liberaAluno(arvore->aluno);
        free(arvore);
    }
}