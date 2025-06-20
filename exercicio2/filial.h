#ifndef _FILIAL_H
#define _FILIAL_H

#include "estoque.h"

#define MAX_NOME_FILIAL 50

typedef struct Filial Filial;

Filial *criaFilial(char *nome);

Filial *leFilial();

char *getNomeFilial(Filial *f);

Estoque *getEstoqueFilial(Filial *f);

void imprimeFilial(Filial *f);

void liberaFilial(Filial *f);

#endif