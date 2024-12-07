#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

#define ROW 3
#define COL 3

// Função para limpar a tela (Windows/Linux)
void limparTela()
{
#ifdef _WIN32
    system("cls"); // Limpa tela no Windows
#else
    system("clear"); // Limpa tela no Linux/Mac
#endif
}

// Função para pausar a execução (Windows/Linux)
void pausar()
{
#ifdef _WIN32
    system("pause");
#else
    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();
#endif
}

void jogoDaVelha()
{
    char matriz[ROW][COL] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int linha, coluna;
    int i, j;

    bool encerrado = 0;
    char simbolo = 'X';

    do
    {
        limparTela();

        printf("\nTabuleiro Atual:\n");
        printf(" %c | %c | %c \n", matriz[0][0], matriz[0][1], matriz[0][2]);
        printf("---|---|---\n");
        printf(" %c | %c | %c \n", matriz[1][0], matriz[1][1], matriz[1][2]);
        printf("---|---|---\n");
        printf(" %c | %c | %c \n", matriz[2][0], matriz[2][1], matriz[2][2]);

        printf("\nDigite uma linha de 0 até %d (vez do %c): ", ROW - 1, simbolo);
        scanf("%d", &linha);
        printf("Digite uma coluna de 0 até %d (vez do %c): ", COL - 1, simbolo);
        scanf("%d", &coluna);

        if (linha < 0 || linha >= ROW || coluna < 0 || coluna >= COL)
        {
            printf("\nPosição inválida! Tente novamente.\n");
            pausar();
            continue;
        }

        if (matriz[linha][coluna] == 'X' || matriz[linha][coluna] == 'O')
        {
            printf("\nPosição já ocupada! Tente novamente.\n");
            pausar();
            continue;
        }

        matriz[linha][coluna] = simbolo;

        for (i = 0; i < ROW; i++)
        {
            if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2] && matriz[i][0] != ' ')
            {
                limparTela();
                printf("\nTabuleiro Final:\n");
                printf(" %c | %c | %c \n", matriz[0][0], matriz[0][1], matriz[0][2]);
                printf("---|---|---\n");
                printf(" %c | %c | %c \n", matriz[1][0], matriz[1][1], matriz[1][2]);
                printf("---|---|---\n");
                printf(" %c | %c | %c \n", matriz[2][0], matriz[2][1], matriz[2][2]);
                printf("\n%c venceu!\n", simbolo);
                encerrado = 1;
                break;
            }
        }

        for (i = 0; i < COL; i++)
        {
            if (matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i] && matriz[0][i] != ' ')
            {
                limparTela();
                printf("\nTabuleiro Final:\n");
                printf(" %c | %c | %c \n", matriz[0][0], matriz[0][1], matriz[0][2]);
                printf("---|---|---\n");
                printf(" %c | %c | %c \n", matriz[1][0], matriz[1][1], matriz[1][2]);
                printf("---|---|---\n");
                printf(" %c | %c | %c \n", matriz[2][0], matriz[2][1], matriz[2][2]);
                printf("\n%c venceu!\n", simbolo);
                encerrado = 1;
                break;
            }
        }

        if (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2] && matriz[0][0] != ' ')
        {
            limparTela();
            printf("\nTabuleiro Final:\n");
            printf(" %c | %c | %c \n", matriz[0][0], matriz[0][1], matriz[0][2]);
            printf("---|---|---\n");
            printf(" %c | %c | %c \n", matriz[1][0], matriz[1][1], matriz[1][2]);
            printf("---|---|---\n");
            printf(" %c | %c | %c \n", matriz[2][0], matriz[2][1], matriz[2][2]);
            printf("\n%c venceu!\n", simbolo);
            encerrado = 1;
        }

        if (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0] && matriz[0][2] != ' ')
        {
            limparTela();
            printf("\nTabuleiro Final:\n");
            printf(" %c | %c | %c \n", matriz[0][0], matriz[0][1], matriz[0][2]);
            printf("---|---|---\n");
            printf(" %c | %c | %c \n", matriz[1][0], matriz[1][1], matriz[1][2]);
            printf("---|---|---\n");
            printf(" %c | %c | %c \n", matriz[2][0], matriz[2][1], matriz[2][2]);
            printf("\n%c venceu!\n", simbolo);
            encerrado = 1;
        }

        int preenchido = 1;
        for (i = 0; i < ROW; i++)
        {
            for (j = 0; j < COL; j++)
            {
                if (matriz[i][j] == ' ')
                {
                    preenchido = 0;
                    break;
                }
            }
        }
        if (preenchido && !encerrado)
        {
            limparTela();
            printf("\nTabuleiro Final:\n");
            printf(" %c | %c | %c \n", matriz[0][0], matriz[0][1], matriz[0][2]);
            printf("---|---|---\n");
            printf(" %c | %c | %c \n", matriz[1][0], matriz[1][1], matriz[1][2]);
            printf("---|---|---\n");
            printf(" %c | %c | %c \n", matriz[2][0], matriz[2][1], matriz[2][2]);
            printf("\nEmpate!\n");
            encerrado = 1;
        }

        simbolo = (simbolo == 'X') ? 'O' : 'X';

    } while (!encerrado);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    jogoDaVelha();

    return 0;
}
