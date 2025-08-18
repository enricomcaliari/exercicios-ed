#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main()
{
    printf("--- Testador de Arvore Binaria ---\n\n");

    // 1. Cria alguns alunos para usar na arvore
    Aluno *a1 = criaAluno("Joao", 101, 8.5);
    Aluno *a2 = criaAluno("Maria", 102, 9.0);
    Aluno *a3 = criaAluno("Pedro", 103, 7.5);
    Aluno *a4 = criaAluno("Ana", 104, 6.0);
    Aluno *a5 = criaAluno("Carlos", 105, 10.0);

    // Aluno repetido para testar a funcao ocorrencias
    Aluno *a6 = criaAluno("Joao", 101, 8.5);

    // 2. Constrói uma arvore de teste
    // Estrutura:
    //      (a3)
    //     /    \
    //  (a1)    (a5)
    //  /   \
    // (a2) (a4)
    // /
    //(a6)

    Arvore *arvore = criaArvore(a3,
                                criaArvore(a1,
                                           criaArvore(a2, criaArvore(a6, criaArvoreVazia(), criaArvoreVazia()), criaArvoreVazia()),
                                           criaArvore(a4, criaArvoreVazia(), criaArvoreVazia())),
                                criaArvore(a5, criaArvoreVazia(), criaArvoreVazia()));

    // 3. Imprime a arvore completa (em pre-ordem)
    printf("--- Imprimindo a arvore em pre-ordem ---\n");
    imprimeArvore(arvore);
    printf("\n");

    // 4. Testa as funcoes de informacao da arvore
    printf("--- Testando funcoes de informacao ---\n");
    printf("A arvore esta vazia? %s\n", arvoreVazia(arvore) ? "Sim" : "Nao");
    printf("Numero de folhas: %d\n", folhas(arvore));
    printf("Altura da arvore: %d\n", altura(arvore));

    printf("\n");

    // 5. Testa a funcao de pertencia
    printf("--- Testando a funcao de pertencia ---\n");
    printf("Aluno 'Pedro' pertence a arvore? %s\n", alunoPertence(arvore, a3) ? "Sim" : "Nao");
    printf("Aluno 'Ana' pertence a arvore? %s\n", alunoPertence(arvore, a4) ? "Sim" : "Nao");
    printf("\n");

    // 6. Testa a funcao de ocorrencias
    printf("--- Testando a funcao de ocorrencias ---\n");
    printf("Numero de ocorrencias do aluno 'Joao': %d\n", ocorrencias(arvore, a1));
    printf("Numero de ocorrencias do aluno 'Pedro': %d\n", ocorrencias(arvore, a3));

    // 7. Testa a funcao arvoreMae
    printf("\n--- Testando a funcao arvoreMae ---\n");
    Arvore *mae = arvoreMae(arvore, a1);
    if (mae != NULL)
    {
        printf("A mae do aluno 'Joao' e o aluno 'Pedro'. O testador encontrou: \n");
        imprimeAluno(retornaAluno(mae));
    }
    else
    {
        printf("Nao foi possivel encontrar a mae do aluno 'Joao'.\n");
    }

    // 8. Libera a memoria da arvore.
    // A funcao liberaArvore deve lidar com a liberacao dos Alunos nos nos.
    arvore = liberaArvore(arvore);

    printf("\n--- Teste de liberacao concluido. Rode com Valgrind para verificar ---\n");

    return 0;
}