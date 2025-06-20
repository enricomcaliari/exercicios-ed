#ifndef _SUPERMERCADO_H
#define _SUPERMERCADO_H

#include "filial.h"

#define MAX_NOME_SUPERMERCADO 50
#define QTD_INICIAL_FILIAIS 2

typedef struct Supermercado Supermercado;

Supermercado *criaSupermercado(char *nome);

Supermercado *leSupermercado();

void *adicionaFilialSupermercado(Supermercado *s, Filial *f);

void calculaEstoqueTotalSupermercado(Supermercado *s);

float getEstoqueTotalSupermercado(Supermercado *s);

int getQtdFiliaisSupermercado(Supermercado *s);

Filial *getFilialSupermercado(Supermercado *s, int i);

void imprimeSupermercado(Supermercado *s);

void liberaSupermercado(Supermercado *s);

#endif