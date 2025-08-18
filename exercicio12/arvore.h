#ifndef arvore_h
#define arvore_h

#include "palavra.h"

typedef struct arvore Arvore;

Arvore *criaArvoreVazia();

Arvore *inserePalavra(Arvore *a, char *texto);

void liberaArvore(Arvore *a);

int contaPalavrasDistintas(Arvore *a);

int contaTotalPalavras(Arvore *a);

Palavra *encontraMaisFrequente(Arvore *a);

Arvore *getArvoreDireita(Arvore *a);

Arvore *getArvoreEsquerda(Arvore *a);

Palavra *getPalavra(Arvore *a);

#endif // arvore_h