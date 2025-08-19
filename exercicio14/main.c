#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int comparaPorFrequencia(const void *a, const void *b)
{
    Palavra *p1 = *(Palavra **)a;
    Palavra *p2 = *(Palavra **)b;

    if (getFrequencia(p1) != getFrequencia(p2))
    {
        return getFrequencia(p1) - getFrequencia(p2);
    }

    return strcmp(getTexto(p1), getTexto(p2));
}

int main()
{
    int tamTabela = 997;
    Hash *hash = criaHash(tamTabela);

    FILE *entrada = fopen("entrada.txt", "r");
    if (entrada == NULL)
    {
        printf("Erro ao abrir arquivo de entrada");
        return 1;
    }

    char palavra[100];
    while (fscanf(entrada, "%s", palavra) != EOF)
    {
        int tamanho = strlen(palavra);
        if ((palavra[tamanho - 1] == '.'))
        {
            palavra[tamanho - 1] = '\0';
        }
        inserePalavraHash(hash, palavra);
    }
    fclose(entrada);

    int palavrasDistintas = getQtdPalavrasDistintas(hash);
    int totalPalavras = getTotalPalavras(hash);
    Palavra *maisFrequente = getPalavraMaisFrequente(hash);

    Palavra **vetorPalavras = (Palavra **)malloc(palavrasDistintas * sizeof(Palavra *));
    preencheVetorPalavras(hash, vetorPalavras);
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
    liberaHash(hash);

    return 0;
}