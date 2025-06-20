#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main()
{
    Lista *lista = criaLista();

    while (1)
    {
        printf("\nMenu:\n");
        printf("Cadastrar novo produto - C\n");
        printf("Remover produto - R\n");
        printf("Imprimir produtos - I\n");
        printf("Finalizar programa - F\n");

        char menu;

        scanf(" %c", &menu);

        if (menu == 'C')
        {
            Produto *produto = leProduto();
            insereProdutoLista(lista, produto);
        }

        else if (menu == 'R')
        {
            printf("\nDigite o codigo do produto a ser removido: ");

            int codigo;
            scanf("%d", &codigo);

            retiraProdutoLista(lista, codigo);
        }

        else if (menu == 'I')
        {
            imprimeLista(lista);
        }

        else if (menu == 'F')
        {
            liberaLista(lista);
            break;
        }
    }

    return 0;
}