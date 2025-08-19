#ifndef arvore_h
#define arvore_h

#include "aluno.h"

typedef struct arvore Arvore;

Arvore *criaArvore();

Arvore *insereAlunoArvore(Arvore *arvore, Aluno *aluno);

Aluno *buscaAlunoArvore(Arvore *arvore, char *nome);

void imprimeArvore(Arvore *arvore);

void liberaArvore(Arvore *arvore);

#endif