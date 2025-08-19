#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int comparaPaises(const void *a, const void *b)
{
    Pais *p1 = *(Pais **)a;
    Pais *p2 = *(Pais **)b;

    if (retornaOuroPais(p1) != retornaOuroPais(p2))
    {
        return retornaOuroPais(p2) - retornaOuroPais(p1);
    }

    if (retornaPrataPais(p1) != retornaPrataPais(p2))
    {
        return retornaPrataPais(p2) - retornaPrataPais(p1);
    }

    if (retornaBronzePais(p1) != retornaBronzePais(p2))
    {
        return retornaBronzePais(p2) - retornaBronzePais(p1);
    }

    return strcmp(retornaNomePais(p1), retornaNomePais(p2));
}

int main()
{
    int tamanho = 97;
    Hash *hash = criaHash(tamanho);

    FILE *entrada = fopen("entrada.txt", "r");
    char nome[4];
    int ouro, prata, bronze, total;
    while (fscanf(entrada, "%s %d %d %d %d\n", nome, &ouro, &prata, &bronze, &total) == 5)
    {
        insereAtualizaPais(hash, nome, ouro, prata, bronze, total);
    }
    fclose(entrada);

    int numPaises = contaPaises(hash);
    Pais **vetorPaises = (Pais **)malloc(numPaises * sizeof(Pais *));
    preencheVetorPaises(hash, vetorPaises);
    qsort(vetorPaises, numPaises, sizeof(Pais *), comparaPaises);

    for (int i = 0; i < numPaises; i++)
    {
        imprimePais(vetorPaises[i]);
    }

    free(vetorPaises);
    liberaHash(hash);

    return 0;
}