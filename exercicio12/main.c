#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

void arvoreParaVetor(Arvore *a, Palavra **vetor, int *i)
{
    if (a != NULL)
    {
        arvoreParaVetor(getArvoreEsquerda(a), vetor, i);
        vetor[*i] = getPalavra(a);
        (*i)++;
        arvoreParaVetor(getArvoreDireita(a), vetor, i);
    }
}

int comparaPorFrequencia(const void *a, const void *b)
{
    Palavra *p1 = *(Palavra **)a;
    Palavra *p2 = *(Palavra **)b;
    return getFrequencia(p1) - getFrequencia(p2);
}

int main()
{
    FILE *entrada = fopen("entrada.txt", "r");
    if (entrada == NULL)
    {
        printf("Erro ao abrir arquivo de entrada");
        return 1;
    }

    Arvore *arvore = criaArvoreVazia();
    char palavra[100];

    while (fscanf(entrada, "%s", palavra) != EOF)
    {
        int tamanho = strlen(palavra);
        if ((palavra[tamanho - 1] == '.'))
        {
            palavra[tamanho - 1] = '\0';
        }
        arvore = inserePalavra(arvore, palavra);
    }
    fclose(entrada);

    int palavrasDistintas = contaPalavrasDistintas(arvore);
    int totalPalavras = contaTotalPalavras(arvore);
    Palavra *maisFrequente = encontraMaisFrequente(arvore);

    Palavra **vetorPalavras = (Palavra **)malloc(palavrasDistintas * sizeof(Palavra *));

    int i = 0;
    arvoreParaVetor(arvore, vetorPalavras, &i);

    qsort(vetorPalavras, palavrasDistintas, sizeof(Palavra *), comparaPorFrequencia);

    for (int j = 0; j < palavrasDistintas; j++)
    {
        printf("%s %d\n", getTexto(vetorPalavras[j]), getFrequencia(vetorPalavras[j]));
    }
    printf("------------------------\n");
    printf("%d palavras distintas encontradas\n", palavrasDistintas);
    printf("%d palavras no total\n", totalPalavras);
    printf("%s é a palavra de maior frequência (%d)\n", getTexto(maisFrequente), getFrequencia(maisFrequente));

    free(vetorPalavras);
    liberaArvore(arvore);

    return 0;
}