#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main()
{

    printf("Informe a quantidade de matrizes:\n");

    int qtdMatrizes;

    scanf("%d", &qtdMatrizes);

    Matriz **matrizes = (Matriz **)malloc(qtdMatrizes * sizeof(Matriz *));

    for (int i = 1; i <= qtdMatrizes; i++)
    {

        printf("Informe o numero de linhas e colunas da matriz %d:\n", i);

        int nlinhas;
        int ncolunas;

        scanf("%d %d", &nlinhas, &ncolunas);

        matrizes[i] = inicializaMatriz(nlinhas, ncolunas);

        for (int x = 0; x < nlinhas; x++)
        {

            for (int y = 0; y < ncolunas; y++)
            {

                int valor;

                printf("Informe o valor da posicao [%d][%d] da matriz %d:\n", x, y, i);

                scanf("%d", &valor);

                modificaElemento(matrizes[i], x, y, valor);
            }
        }
    }

    char opcao;

    do
    {

        printf("Escolha a operacao:\n");
        printf("A - Imprimir todas as matrizes\n");
        printf("B - Imprimir transposta de uma matriz\n");
        printf("C - Multiplicar duas matrizes\n");
        printf("F - Finaliza Programa\n");

        scanf(" %c", &opcao);

        if (opcao == 'A')
        {

            for (int i = 1; i <= qtdMatrizes; i++)
            {

                printf("Matriz %d:\n", i);

                imprimeMatriz(matrizes[i]);
            }
        }

        else if (opcao == 'B')
        {

            int num;

            printf("Digite a matriz a ser transposta: ");

            scanf("%d", &num);

            Matriz *t = transposta(matrizes[num]);

            printf("Matriz transposta:\n");

            imprimeMatriz(t);
            destroiMatriz(t);
        }

        else if (opcao == 'C')
        {

            int num1, num2;

            printf("Matrizes a serem multiplicadas: ");

            scanf("%d %d", &num1, &num2);

            Matriz *m = multiplicacao(matrizes[num1], matrizes[num2]);

            printf("Resultado:\n");

            imprimeMatriz(m);
            destroiMatriz(m);
        }
    } while (opcao != 'F');

    for (int i = 0; i < qtdMatrizes; i++)
    {

        destroiMatriz(matrizes[i]);
    }

    free(matrizes);

    return 0;
}
