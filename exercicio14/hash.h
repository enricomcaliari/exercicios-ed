#ifndef hash_h
#define hash_h

#include "palavra.h"

typedef struct hash Hash;

Hash *criaHash(int tamTabela);

void liberaHash(Hash *hash);

int valorTexto(char *texto);

int chaveHash(char *texto, int tamTabela);

void inserePalavraHash(Hash *hash, char *texto);

int getTotalPalavras(Hash *hash);

int getQtdPalavrasDistintas(Hash *hash);

Palavra *getPalavraMaisFrequente(Hash *hash);

void preencheVetorPalavras(Hash *hash, Palavra **vetor);

#endif