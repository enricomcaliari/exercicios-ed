#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

struct arvore
{
    Aluno *aluno;
    struct arvore *esquerda;
    struct arvore *direita;
};

Arvore *criaArvoreVazia()
{
    return NULL; // Retorna NULL para indicar que a árvore está vazia
}

Arvore *criaArvore(Aluno *aluno, Arvore *esquerda, Arvore *direita)
{
    Arvore *arvore = (Arvore *)malloc(sizeof(Arvore));
    arvore->aluno = aluno;
    arvore->esquerda = esquerda;
    arvore->direita = direita;
    return arvore;
}

Arvore *arvoreMae(Arvore *arvore, Aluno *aluno)
{
    if (arvoreVazia(arvore))
        return NULL; // Se a árvore estiver vazia, retorna NULL

    // Verifica se o aluno está na raiz
    if (arvore->aluno == aluno)
        return arvore;

    // Busca recursivamente nas subárvores esquerda e direita
    Arvore *maeEsquerda = arvoreMae(arvore->esquerda, aluno);
    if (maeEsquerda != NULL)
        return maeEsquerda;

    return arvoreMae(arvore->direita, aluno); // Retorna NULL se não encontrar
}

Aluno *retornaAluno(Arvore *arvore)
{
    return arvoreVazia(arvore) ? NULL : arvore->aluno; // Retorna o aluno na raiz ou NULL se a árvore estiver vazia
}

int arvoreVazia(Arvore *arvore)
{
    return arvore == NULL; // Retorna 1 se a árvore estiver vazia, 0 caso contrário
}

int alunoPertence(Arvore *arvore, Aluno *aluno)
{
    if (arvoreVazia(arvore))
        return 0; // Se a árvore estiver vazia, o aluno não pertence
    else
        return arvore->aluno == aluno || alunoPertence(arvore->esquerda, aluno) || alunoPertence(arvore->direita, aluno);
}

int folhas(Arvore *arvore)
{
    if (arvoreVazia(arvore))
        return 0; // Se a árvore estiver vazia, não há folhas

    // Se o nó atual não tem filhos, é uma folha
    if (arvore->esquerda == NULL && arvore->direita == NULL)
        return 1;

    // Soma as folhas das subárvores esquerda e direita
    return folhas(arvore->esquerda) + folhas(arvore->direita);
}

int ocorrencias(Arvore *arvore, Aluno *aluno)
{
    if (arvoreVazia(arvore))
        return 0; // Se a árvore estiver vazia, não há ocorrências

    // Conta a ocorrência do aluno na raiz e nas subárvores
    return (arvore->aluno == aluno) + ocorrencias(arvore->esquerda, aluno) + ocorrencias(arvore->direita, aluno);
}

int altura(Arvore *arvore)
{
    if (arvoreVazia(arvore))
        return 0; // Se a árvore estiver vazia, a altura é 0

    // Calcula a altura das subárvores esquerda e direita
    int alturaEsquerda = altura(arvore->esquerda);
    int alturaDireita = altura(arvore->direita);

    // A altura da árvore é o máximo entre as alturas das subárvores mais 1 para o nó atual
    return (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita) + 1;
}

void imprimeArvore(Arvore *arvore)
{
    if (!arvoreVazia(arvore))
    {
        imprimeAluno(arvore->aluno);     // Imprime o aluno na raiz
        imprimeArvore(arvore->esquerda); // Imprime a subárvore esquerda
        imprimeArvore(arvore->direita);  // Imprime a subárvore direita
    }
}

Arvore *liberaArvore(Arvore *arvore)
{
    if (!arvoreVazia(arvore))
    {
        liberaAluno(arvore->aluno);     // Libera o aluno na raiz
        liberaArvore(arvore->esquerda); // Libera a subárvore esquerda
        liberaArvore(arvore->direita);  // Libera a subárvore direita
        free(arvore);                   // Libera o nó atual da árvore
    }
    return NULL; // Retorna NULL para indicar que a árvore foi liberada
}