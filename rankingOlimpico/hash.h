#ifndef hash_h
#define hash_h

#include "pais.h"

typedef struct hash Hash;

Hash *criaHash(int tamanho);

int valorString(char *string);

int chaveHash(char *string, int tamanho);

void insereAtualizaPais(Hash *hash, char *nome, int ouro, int prata, int bronze, int total);

int preencheVetorPaises(Hash *hash, Pais **vetor);

int contaPaises(Hash *hash);

void liberaHash(Hash *hash);

#endif