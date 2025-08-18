#ifndef arvore_h
#define arvore_h

#include "aluno.h"

typedef struct arvore Arvore;

Arvore *criaArvoreVazia();

Arvore *criaArvore(Aluno *aluno, Arvore *esquerda, Arvore *direita);

Arvore *arvoreMae(Arvore *arvore, Aluno *aluno);

Aluno *retornaAluno(Arvore *arvore);

int arvoreVazia(Arvore *arvore);

int alunoPertence(Arvore *arvore, Aluno *aluno);

int folhas(Arvore *arvore);

int ocorrencias(Arvore *arvore, Aluno *aluno);

int altura(Arvore *arvore);

void imprimeArvore(Arvore *arvore);

Arvore *liberaArvore(Arvore *arvore);

#endif // arvore_h