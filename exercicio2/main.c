#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supermercado.h"

int main()
{
    Supermercado *supermercado = leSupermercado();

    Filial *filialInicial = leFilial();

    adicionaFilialSupermercado(supermercado, filialInicial);

    char menu;
    while (1)
    {
        printf("\nMenu:\n");
        printf("Cadastrar nova filial - F\n");
        printf("Cadastrar novo produto - P\n");
        printf("Imprimir relatorio - I\n");
        printf("Encerrar programa - E\n");

        scanf("%c\n", &menu);

        if (menu == 'F' || menu == 'f')
        {
            Filial *filial = leFilial();
            adicionaFilialSupermercado(supermercado, filial);
        }

        else if (menu == 'P' || menu == 'p')
        {
            Produto *produto = leProduto();
            printf("\nDigite a filial na qual o produto sera cadastrado:\n");

            char filial[MAX_NOME_FILIAL];
            scanf("%49[^\n]\n", filial);

            int check = 0;
            for (int i = 0; i < getQtdFiliaisSupermercado(supermercado); i++)
            {
                if (!strcmp(filial, getNomeFilial(getFilialSupermercado(supermercado, i))))
                {
                    adicionaProdutoEstoque(getEstoqueFilial(getFilialSupermercado(supermercado, i)), produto);
                    check = 1;
                }
            }

            if (!check)
            {
                printf("Filial inexistente\n");
                liberaProduto(produto);
            }
        }

        else if (menu == 'I' || menu == 'i')
        {
            calculaEstoqueTotalSupermercado(supermercado);
            imprimeSupermercado(supermercado);
        }

        else
        {
            liberaSupermercado(supermercado);
            break;
        }
    }

    return 0;
}