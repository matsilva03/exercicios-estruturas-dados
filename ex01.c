#include <stdio.h>
#include <locale.h>

#define ROW 3
#define COL 3

void maiorMenorMatriz()
{
    float matriz[ROW][COL];
    int i, j;

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            printf("Informe o %d° valor da %d° linha: ", j + 1, i + 1);
            scanf("%f", &matriz[i][j]);
        }
    }

    float maior = matriz[0][0], menor = matriz[0][0];

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            if (matriz[i][j] > maior)
            {
                maior = matriz[i][j];
            }
            if (matriz[i][j] < menor)
            {
                menor = matriz[i][j];
            }
        }
    }

    printf("\nMaior número da matriz: %.2f\n", maior);
    printf("Menor número da matriz: %.2f\n", menor);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    maiorMenorMatriz();
    return 0;
}
