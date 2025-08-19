#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

int main()
{
    int n;
    FILE *entrada = fopen("entrada.txt", "r");

    fscanf(entrada, "N %d\n", &n);

    char nome[MAX_NOME];
    Arvore *arvore = criaArvore();

    while (fscanf(entrada, "%s\n", nome) == 1)
    {
        Aluno *aluno = criaAluno(nome, 0, 0);
        arvore = insereAlunoArvore(arvore, aluno);
    }
    fclose(entrada);

    for (int i = 1; i <= n; i++)
    {
        char frequencia;
        char arquivo[50];
        sprintf(arquivo, "entrada%d.txt", i);

        FILE *entradas = fopen(arquivo, "r");

        while (fscanf(entradas, "%s %c\n", nome, &frequencia) == 2)
        {
            Aluno *aluno = buscaAlunoArvore(arvore, nome);
            if (aluno != NULL)
            {
                if (frequencia == 'P')
                {
                    incrementaPresencasAluno(aluno);
                }
                else
                {
                    incrementaFaltasAluno(aluno);
                }
            }
        }
        fclose(entradas);
    }

    imprimeArvore(arvore);
    liberaArvore(arvore);

    return 0;
}