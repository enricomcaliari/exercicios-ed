#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// exercicio 1
#define PI 3.14
void calc_esfera(float r, float *area, float *volume)
{
    float a = 4 * PI * pow(r, 2);
    float v = 4 * PI * pow(r, 3) / 3;
    *area = a;
    *volume = v;
}

// exercicio 2
int raizes(float a, float b, float c, float *x1, float *x2)
{
    float delta = pow(b, 2) - 4 * a * c;

    if (delta >= 0 && a != 0)
    {
        float raiz1 = (-b - sqrt(delta)) / (2 * a);
        float raiz2 = (-b + sqrt(delta)) / (2 * a);
        *x1 = raiz1;
        *x2 = raiz2;
        return 1;
    }
    else
        return 0;
}

// exercicio 3
int pares(int n, int *vet)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (vet[i] % 2 == 0)
        {
            count++;
        }
    }
    return count;
}

// exercicio 4
void inverte(int n, int *vet)
{
    for (int i = 0; i < n / 2; i++)
    {
        int backup = vet[i];
        vet[i] = vet[n - 1 - i];
        vet[n - 1 - i] = backup;
    }
}

// exercicio 5
double avalia(double *poli, int grau, double x)
{
    double resultado = 0;
    for (int i = 0; i < grau; i++)
    {
        resultado += pow(x, i) * poli[i];
    }
    return resultado;
}

int main()
{
    int exercicio;
    printf("Digite o numero do exercicio:\n");
    scanf("%d", &exercicio);

    if (exercicio == 1)
    {
        float r, area, volume;
        printf("Digite o raio da esfera:\n");
        scanf("%f", &r);

        if (r > 0)
        {
            calc_esfera(r, &area, &volume);
            printf("Area: %.2f\nVolume: %.2f\n", area, volume);
        }
        else
            printf("Raio invalido\n");
    }

    else if (exercicio == 2)
    {
        float a, b, c, x1, x2;
        printf("Digite as constantes da equacao:\n");
        scanf("%f %f %f", &a, &b, &c);

        int equacaoValida = raizes(a, b, c, &x1, &x2);
        if (equacaoValida)
        {
            printf("Raizes: %.2f e %.2f\n", x1, x2);
        }
        else
            printf("Constantes invalidas\n");
    }

    else if (exercicio == 3)
    {
        int n;
        printf("Digite o tamanho do vetor:\n");
        scanf("%d", &n);

        if (n > 0)
        {
            int *vet = (int *)malloc(n * sizeof(int));

            printf("Digite os elementos do vetor:\n");
            for (int i = 0; i < n; i++)
            {
                if (i < n - 1)
                {
                    scanf("%d ", &vet[i]);
                }
                else
                    scanf("%d", &vet[i]);
            }

            printf("Quantidade de numeros pares no vetor: %d\n", pares(n, vet));

            free(vet);
        }
        else
            printf("Tamanho invalido\n");
    }

    else if (exercicio == 4)
    {
        int n;
        printf("Digite o tamanho do vetor:\n");
        scanf("%d", &n);

        if (n > 0)
        {
            int *vet = (int *)malloc(n * sizeof(int));
            printf("Digite os elementos do vetor:\n");
            for (int i = 0; i < n; i++)
            {
                if (i < n - 1)
                {
                    scanf("%d ", &vet[i]);
                }
                else
                    scanf("%d", &vet[i]);
            }

            inverte(n, vet);
            printf("Vetor invertido: ");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", vet[i]);
            }
            printf("\n");

            free(vet);
        }
        else
            printf("Tamanho invalido\n");
    }

    else if (exercicio == 5)
    {
        int grau;
        printf("Digite o grau do polinomio:\n");
        scanf("%d", &grau);

        if (grau > 0)
        {
            grau++;
            double *poli = (double *)malloc(grau * sizeof(double));
            printf("Digite a constante e os coeficientes do polinomio:\n");
            for (int i = 0; i < grau; i++)
            {
                if (i < grau - 1)
                {
                    scanf("%lf ", &poli[i]);
                }
                else
                    scanf("%lf", &poli[i]);
            }

            double x;
            printf("Digite o valor de x:\n");
            scanf("%lf", &x);

            printf("Resultado: %.2lf\n", avalia(poli, grau, x));

            free(poli);
        }
        else
            printf("Grau invalido\n");
    }

    else
    {
        printf("Exercicio invalido\n");
    }

    return 0;
}