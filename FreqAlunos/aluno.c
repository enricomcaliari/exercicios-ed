#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno
{
    char *nome;
    int presencas, faltas;
};

Aluno *criaAluno(char *nome, int presencas, int faltas)
{
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
    aluno->nome = strdup(nome);
    aluno->presencas = presencas;
    aluno->faltas = faltas;
    return aluno;
}

void incrementaPresencasAluno(Aluno *aluno)
{
    aluno->presencas++;
}

void incrementaFaltasAluno(Aluno *aluno)
{
    aluno->faltas++;
}

char *retornaNomeAluno(Aluno *aluno)
{
    return aluno->nome;
}

void imprimeAluno(Aluno *aluno)
{
    if (aluno != NULL)
    {
        printf("%s %dP %dF\n", aluno->nome, aluno->presencas, aluno->faltas);
    }
}

void liberaAluno(Aluno *aluno)
{
    if (aluno != NULL)
    {
        free(aluno->nome);
        free(aluno);
    }
}