#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno
{
    char *nome;
    int matricula;
    float media;
};

Aluno *criaAluno(char *nome, int matricula, float media)
{
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));

    aluno->nome = (char *)malloc(MAX_NOME * sizeof(char));

    strcpy(aluno->nome, nome);
    aluno->matricula = matricula;
    aluno->media = media;

    return aluno;
}

void imprimeAluno(Aluno *aluno)
{
    if (aluno != NULL)
    {
        printf("Nome: %s\n", aluno->nome);
        printf("Matrícula: %d\n", aluno->matricula);
        printf("Média: %.2f\n", aluno->media);
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