#include <stdio.h>
#include <locale.h>

void centroMeteorologico()
{
    const int QUANT_CIDADES = 7;
    const int QUANT_MESES = 6;
    const char MESES[][6] = {"Jan", "Fev", "Mar", "Abr", "Mai", "Jun"};

    float indicePluviometrico[QUANT_CIDADES][QUANT_MESES];
    float somaMeses[QUANT_MESES] = {0};

    int i, j;
    float soma, pluvMediaCidade;

    for (i = 0; i < QUANT_CIDADES; i++)
    {
        soma = 0;

        for (j = 0; j < QUANT_MESES; j++)
        {
            printf("Insira o índice pluviométrico da %dª cidade no mês de %s: ", i + 1, MESES[j]);
            scanf("%f", &indicePluviometrico[i][j]);

            soma += indicePluviometrico[i][j];
            somaMeses[j] += indicePluviometrico[i][j];
        }

        pluvMediaCidade = soma / QUANT_MESES;
        printf("Índice de pluviosidade médio da cidade %d: %.2f\n", i + 1, pluvMediaCidade);
    }

    printf("\nÍndice de pluviosidade médio por mês:\n");
    for (j = 0; j < QUANT_MESES; j++)
    {
        printf("Mês de %s: %.2f\n", MESES[j], somaMeses[j] / QUANT_CIDADES);
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    centroMeteorologico();
    return 0;
}