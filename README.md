# Lista de Exercícios de Estrutura de Dados

## Questão 1

**Descrição:** Suponha uma matriz de 3 linhas por 3 colunas do tipo inteiro. Leia os valores dessa matriz e informe o maior e o menor elemento.

**[Solução](Questao1.c)**

---

## Questão 2

**Descrição:** Suponha uma matriz de 3 linhas por 3 colunas do tipo inteiro. Leia os valores dessa matriz e informe o maior e o menor elemento.  

**[Solução](Questao2.c)**

---

## Questão 3

**Descrição:** Notas da turma – Faça um programa para ler as notas de 4 provas para 5 alunos de uma turma. Calcule a média de cada aluno e a média da turma.  

**[Solução](Questao3.c)**

---

## Questão 4

**Descrição:** Centro meteorológico – Um centro meteorológico distribuiu dispositivos para registrar índices pluviométricos em 7 cidades de uma região (identificadas por códigos numéricos de 1 a 7) durante 6 meses (jan a jun). Para cada mês, foi registrado um valor real correspondente ao índice pluviométrico total.

Escreva um programa que leia os índices pluviométricos e imprima:  

- O índice de pluviosidade médio mensal de cada cidade;  
- O índice de pluviosidade médio de cada mês na região.  

**[Solução](Questao4.c)**

---

## Questão 5

**Descrição:** Quais serão os valores de `x`, `y` e `p` ao final do trecho de código abaixo? Justifique sua resposta.

```c
int x, y, *p;

y = 0;
p = &y;
x = *p;
x = 4;
(*p)++;
--x;
(*p) += x;

```

**[Solução](Questao5.c)**

---

## Questão 6

**Descrição:** Desenvolva um programa em Linguagem C para criar uma estrutura de dados `voo` (`struct voo`) para a empresa VOEBEM. Essa estrutura deve ser dinâmica e conter os seguintes dados:

- **Número do voo:** inteiro;  
- **Data do voo:** inteiro (1 - seg, 2 - ter, 3 - qua, 4 - qui, 5 - sex, 6 - sáb, 7 - dom, 8 - diário);  
- **Horário do voo:** `hora` (inteiro), `min` (inteiro);  
- **Aeroporto de saída:** inteiro (ID do aeroporto);  
- **Aeroporto de chegada:** inteiro (ID do aeroporto);  
- **Rota:** inteiro (ID);  
- **Tempo estimado de voo:** float;  
- **Passageiros a bordo:** inteiro.  

**[Solução](https://github.com/matsilva03/exercicios-estruturas-dados/blob/4859f91ccdeee6a36b718ce27cb2637a34b595d4/ex06_07_08_09.c#L6-L35)**

---

## Questão 7

**Descrição:** Implemente a função `cadastrarVoo()` para permitir o cadastro de um novo voo.  

**[Solução](https://github.com/matsilva03/exercicios-estruturas-dados/blob/4859f91ccdeee6a36b718ce27cb2637a34b595d4/ex06_07_08_09.c#L126-L143)**

---

## Questão 8

**Descrição:** Implemente a função `consultaVoo()` para obter informações sobre um voo com base no número do voo.  

**[Solução](https://github.com/matsilva03/exercicios-estruturas-dados/blob/4859f91ccdeee6a36b718ce27cb2637a34b595d4/ex06_07_08_09.c#L145-L196)**

---

## Questão 9

**Descrição:** Implemente a função `removeVoo()` para permitir a exclusão de um voo.  

**[Solução](https://github.com/matsilva03/exercicios-estruturas-dados/blob/4859f91ccdeee6a36b718ce27cb2637a34b595d4/ex06_07_08_09.c#L198-L227)**

---

## Questão 10

**Descrição:** Desenvolva uma rotina recursiva para calcular a somatória de todos os números de 1 a `N` (lido do teclado).  

**Observação:** Se `N = 5`, por exemplo, a somatória será igual a 15, ou seja, \( 1 + 2 + 3 + 4 + 5 = 15 \).  

**[Solução](Questao10.c)**
