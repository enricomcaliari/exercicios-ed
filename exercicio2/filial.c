#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filial.h"

struct Filial
{
    char *nome;
    Estoque *estoque;
};

Filial *criaFilial(char *nome)
{
    Filial *f = (Filial *)malloc(sizeof(Filial));
    f->nome = (char *)malloc(MAX_NOME_FILIAL * sizeof(char));
    f->estoque = criaEstoque();
    strcpy(f->nome, nome);
    return f;
}

Filial *leFilial()
{
    printf("\nDigite o nome da filial:\n");

    char nome[MAX_NOME_FILIAL];
    scanf("%49[^\n]\n", nome);

    Filial *f = criaFilial(nome);

    return f;
}

char *getNomeFilial(Filial *f)
{
    return f->nome;
}

Estoque *getEstoqueFilial(Filial *f)
{
    return f->estoque;
}

void imprimeFilial(Filial *f)
{
    printf("    Filial: %s\n", f->nome);
    imprimeEstoque(f->estoque);
}

void liberaFilial(Filial *f)
{
    if (f != NULL)
    {
        free(f->nome);
        liberaEstoque(f->estoque);
        free(f);
    }
}