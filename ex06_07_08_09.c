#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Estrutura de um voo
typedef struct voo
{
    int numero;
    int data;
    int hora, minuto;
    int aeroportoSaida, aeroportoChegada;
    int rota;
    float tempoEstimado;
    int passageiros;
    struct voo *prox;
} Voo;

// Função para criar um novo voo
Voo *criarVoo(int numero, int data, int hora, int minuto, int aeroportoSaida,
              int aeroportoChegada, int rota, float tempoEstimado, int passageiros)
{
    Voo *novoVoo = (Voo *)malloc(sizeof(Voo));
    novoVoo->numero = numero;
    novoVoo->data = data;
    novoVoo->hora = hora;
    novoVoo->minuto = minuto;
    novoVoo->aeroportoSaida = aeroportoSaida;
    novoVoo->aeroportoChegada = aeroportoChegada;
    novoVoo->rota = rota;
    novoVoo->tempoEstimado = tempoEstimado;
    novoVoo->passageiros = passageiros;
    novoVoo->prox = NULL;
    return novoVoo;
}

// Função para validar entradas inteiras
int lerInteiro(const char *prompt)
{
    int num;
    while (1)
    {
        printf("%s", prompt);
        if (scanf("%d", &num) == 1 && num > 0)
        {
            return num;
        }
        else
        {
            while (getchar() != '\n')
                ; // Limpar o buffer de entrada
            printf("Entrada inválida. Por favor, insira um número inteiro positivo.\n");
        }
    }
}

// Função para validar entradas de ponto flutuante
float lerFloat(const char *prompt)
{
    float num;
    while (1)
    {
        printf("%s", prompt);
        if (scanf("%f", &num) == 1 && num > 0)
        {
            return num;
        }
        else
        {
            while (getchar() != '\n')
                ; // Limpar o buffer de entrada
            printf("Entrada inválida. Por favor, insira um número válido.\n");
        }
    }
}

// Função para ler a data (com validação e opções de seleção)
int lerData()
{
    int data;
    do
    {
        printf("\nSelecione o dia da semana para o voo:\n");
        printf("1 - Segunda-feira\n");
        printf("2 - Terça-feira\n");
        printf("3 - Quarta-feira\n");
        printf("4 - Quinta-feira\n");
        printf("5 - Sexta-feira\n");
        printf("6 - Sábado\n");
        printf("7 - Domingo\n");
        printf("8 - Diário\n");
        printf("Digite a opção correspondente: ");
        scanf("%d", &data);

        if (data >= 1 && data <= 8)
        {
            return data;
        }
        else
        {
            printf("Opção inválida! Por favor, escolha um número entre 1 e 8.\n");
        }
    } while (1);
}

// Função para ler o horário (hora e minuto)
void lerHorario(int *hora, int *minuto)
{
    while (1)
    {
        *hora = lerInteiro("Digite a hora (0-23): ");
        *minuto = lerInteiro("Digite os minutos (0-59): ");

        // Validação da hora e minutos
        if (*hora >= 0 && *hora <= 23 && *minuto >= 0 && *minuto <= 59)
        {
            break; // Entrada válida
        }
        else
        {
            printf("Horário inválido! A hora deve ser entre 0 e 23, e os minutos entre 0 e 59.\n");
        }
    }
}

// Função para cadastrar um novo voo na lista
void cadastrarVoo(Voo **lista, Voo *novoVoo)
{
    if (*lista == NULL)
    {
        *lista = novoVoo;
    }
    else
    {
        Voo *temp = *lista;
        while (temp->prox != NULL)
        {
            temp = temp->prox;
        }
        temp->prox = novoVoo;
    }
    printf("Voo %d cadastrado com sucesso!\n", novoVoo->numero);
}

// Função para consultar um voo pelo número
void consultaVoo(Voo *lista, int numero)
{
    Voo *temp = lista;
    while (temp != NULL)
    {
        if (temp->numero == numero)
        {
            printf("\nInformações do Voo %d:\n", temp->numero);
            printf("Data: ");
            switch (temp->data)
            {
            case 1:
                printf("Segunda-feira\n");
                break;
            case 2:
                printf("Terça-feira\n");
                break;
            case 3:
                printf("Quarta-feira\n");
                break;
            case 4:
                printf("Quinta-feira\n");
                break;
            case 5:
                printf("Sexta-feira\n");
                break;
            case 6:
                printf("Sábado\n");
                break;
            case 7:
                printf("Domingo\n");
                break;
            case 8:
                printf("Diário\n");
                break;
            default:
                printf("Data inválida\n");
                break;
            }
            printf("Horário: %02d:%02d\n", temp->hora, temp->minuto);
            printf("Aeroporto de Saída: %d\n", temp->aeroportoSaida);
            printf("Aeroporto de Chegada: %d\n", temp->aeroportoChegada);
            printf("Rota: %d\n", temp->rota);
            printf("Tempo Estimado: %.2f horas\n", temp->tempoEstimado);
            printf("Passageiros a bordo: %d\n", temp->passageiros);
            return;
        }
        temp = temp->prox;
    }
    printf("Voo %d não encontrado.\n", numero);
}

// Função para remover um voo pelo número
void removeVoo(Voo **lista, int numero)
{
    Voo *temp = *lista;
    Voo *anterior = NULL;

    while (temp != NULL && temp->numero != numero)
    {
        anterior = temp;
        temp = temp->prox;
    }

    if (temp == NULL)
    {
        printf("Voo %d não encontrado.\n", numero);
        return;
    }

    if (anterior == NULL)
    {
        *lista = temp->prox;
    }
    else
    {
        anterior->prox = temp->prox;
    }

    free(temp);
    printf("Voo %d removido com sucesso!\n", numero);
}

// Função principal
int main()
{
    setlocale(LC_ALL, "Portuguese");

    Voo *listaVoos = NULL;
    int opcao, numero, data, hora, minuto, aeroportoSaida, aeroportoChegada, rota, passageiros;
    float tempoEstimado;

    do
    {
        printf("\n--- Menu ---\n");
        printf("1. Cadastrar Voo\n");
        printf("2. Consultar Voo\n");
        printf("3. Remover Voo\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        if (scanf("%d", &opcao) != 1)
        {
            printf("Entrada inválida!\n");
            while (getchar() != '\n')
                ; // Limpar o buffer de entrada
            continue;
        }

        switch (opcao)
        {
        case 1:
            numero = lerInteiro("Digite o número do voo: ");
            data = lerData();
            lerHorario(&hora, &minuto);
            aeroportoSaida = lerInteiro("Digite o ID do aeroporto de saída: ");
            aeroportoChegada = lerInteiro("Digite o ID do aeroporto de chegada: ");
            rota = lerInteiro("Digite o ID da rota: ");
            tempoEstimado = lerFloat("Digite o tempo estimado de voo (em horas): ");
            passageiros = lerInteiro("Digite o número de passageiros a bordo: ");

            Voo *novoVoo = criarVoo(numero, data, hora, minuto, aeroportoSaida, aeroportoChegada, rota, tempoEstimado, passageiros);
            cadastrarVoo(&listaVoos, novoVoo);
            break;

        case 2:
            numero = lerInteiro("Digite o número do voo a consultar: ");
            consultaVoo(listaVoos, numero);
            break;

        case 3:
            numero = lerInteiro("Digite o número do voo a remover: ");
            removeVoo(&listaVoos, numero);
            break;

        case 4:
            printf("Encerrando o programa.\n");
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 4);

    // Liberar memória antes de encerrar
    while (listaVoos != NULL)
    {
        Voo *temp = listaVoos;
        listaVoos = listaVoos->prox;
        free(temp);
    }

    return 0;
}
