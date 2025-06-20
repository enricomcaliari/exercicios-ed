#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

// Tipo matriz (tipo opaco)
// Estrutura interna do tipo deve ser definida na implementacao do TAD
struct matriz
{

    int nlinhas;
    int ncolunas;
    int **valores;
};

/*Inicializa uma matriz de nlinhas e ncolunas
 * inputs: nlinhas (no de linhas) e ncolunas (no de colunas)
 * output: ponteiro para a matriz inicializada
 * pre-condicao: nlinhas e ncolunas diferentes de 0
 * pos-condicao: matriz de retorno existe e contem nlinhas e ncolunas
 */
Matriz *inicializaMatriz(int nlinhas, int ncolunas)
{

    if (nlinhas != 0 && ncolunas != 0)
    {

        Matriz *mat = (Matriz *)calloc(1, sizeof(Matriz));

        mat->nlinhas = nlinhas;
        mat->ncolunas = ncolunas;

        mat->valores = (int **)calloc(nlinhas, sizeof(int *));

        for (int i = 0; i < nlinhas; i++)
        {

            mat->valores[i] = (int *)calloc(ncolunas, sizeof(int));
        }

        return mat;
    }
}

/*Modifica o elemento [linha][coluna] da matriz mat
 * inputs: a matriz, a linha, a coluna, e o novo elemento
 * output: nenhum
 * pre-condicao: matriz mat existe, linha e coluna sao validos na matriz
 * pos-condicao: elemento [linha][coluna] da matriz modificado
 */
void modificaElemento(Matriz *mat, int linha, int coluna, int elem)
{

    if (mat != NULL && linha < mat->nlinhas && coluna < mat->ncolunas)
    {

        mat->valores[linha][coluna] = elem;
    }
}

/*Retorna o elemento mat[linha][coluna]
 * inputs: a matriz, a linha e a coluna
 * output: elemento mat[linha][coluna]
 * pre-condicao: matriz mat existe, linha e coluna sao validos na matriz
 * pos-condicao: mat nao eh modificada
 */
int recuperaElemento(Matriz *mat, int linha, int coluna)
{

    if (mat != NULL)
    {

        return mat->valores[linha][coluna];
    }
}

/*Retorna o numero de colunas da matriz mat
 * inputs: a matriz
 * output: o numero de colunas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat nao eh modificada
 */
int recuperaNColunas(Matriz *mat)
{

    if (mat != NULL)
    {

        return mat->ncolunas;
    }
}

/*Retorna o numero de linhas da matriz mat
 * inputs: a matriz
 * output: o numero de linhas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat nao eh modificada
 */
int recuperaNLinhas(Matriz *mat)
{

    if (mat != NULL)
    {

        return mat->nlinhas;
    }
}

/*Retorna a matriz transposta de mat
 * inputs: a matriz
 * output: a matriz transposta
 * pre-condicao: matriz mat existe
 * pos-condicao: mat nao eh modificada e matriz transposta existe
 */
Matriz *transposta(Matriz *mat)
{

    if (mat != NULL)
    {

        Matriz *trans = inicializaMatriz(mat->ncolunas, mat->nlinhas);

        for (int i = 0; i < mat->nlinhas; i++)
        {

            for (int j = 0; j < mat->ncolunas; j++)
            {

                trans->valores[j][i] = mat->valores[i][j];
            }
        }

        return trans;
    }
}

/*Retorna a matriz multiplicacao entre mat1 e mat2
 * inputs: as matrizes mat1 e mat2
 * output: a matriz multiplicacao
 * pre-condicao: matrizes mat1 e mat2 existem, e o numero de colunas de mat1 correponde ao numero de linhas de mat2
 * pos-condicao: mat1 e mat2 nao sao modificadas e a matriz multiplicacao existe
 */
Matriz *multiplicacao(Matriz *mat1, Matriz *mat2)
{

    if (mat1 != NULL && mat2 != NULL && mat1->ncolunas == mat2->nlinhas)
    {

        Matriz *resultado = inicializaMatriz(mat1->nlinhas, mat2->ncolunas);

        for (int i = 0; i < mat1->nlinhas; i++)
        {

            for (int j = 0; j < mat2->ncolunas; j++)
            {

                int soma = 0;

                for (int k = 0; k < mat1->ncolunas; k++)
                {

                    soma += mat1->valores[i][k] * mat2->valores[k][j];
                }

                resultado->valores[i][j] = soma;
            }
        }

        return resultado;
    }
}

/*Imprime a matriz completa
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: nenhuma
 */
void imprimeMatriz(Matriz *mat)
{

    if (mat != NULL)
    {

        for (int i = 0; i < mat->nlinhas; i++)
        {

            for (int j = 0; j < mat->ncolunas; j++)
            {

                printf("%d ", mat->valores[i][j]);
            }

            printf("\n");
        }
    }
}

/*Imprime apenas uma linha da matriz
 * inputs: matriz mat e o indice da linha
 * output: nenhum
 * pre-condicao: matriz mat existe e indice eh valido na matriz
 * pos-condicao: nenhuma
 */
void imprimeLinha(Matriz *mat, int indice)
{

    if (mat != NULL && indice < mat->nlinhas)
    {

        for (int i = 0; i < mat->ncolunas; i++)
        {

            printf("%d ", mat->valores[indice][i]);
        }

        printf("\n");
    }
}

/*Libera toda a memoria alocada para a matriz
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: memoria ocupada por linhas e colunas liberada!
 */
void destroiMatriz(Matriz *mat)
{

    if (mat != NULL)
    {

        for (int i = 0; i < mat->nlinhas; i++)
        {

            free(mat->valores[i]);
        }

        free(mat->valores);
        free(mat);
    }
}