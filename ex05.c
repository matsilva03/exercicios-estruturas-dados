#include <stdio.h>

int main()
{
    /**
     * Declaração das variáveis x e y, e do pornteiro *p
     *
     *  x -> sem valor
     *  y -> sem valor
     *  p -> sem valor
     * *p -> sem valor
     */
    int x, y, *p;

    /**
     * Atribuição do valor 0 à variável y.
     *
     *  x -> sem valor
     *  y -> 0
     *  p -> sem valor
     * *p -> sem valor
     */
    y = 0;

    /**
     * Atribuição do endereço de y ao ponteiro p.
     *
     *  x -> sem valor
     *  y -> 0
     *  p -> endereço de y
     * *p -> 0
     */
    p = &y;

    /**
     * Atribuição do valor armazenado no endereço apontado por p.
     *
     *  x -> 0
     *  y -> 0
     *  p -> endereço de y
     * *p -> 0
     */
    x = *p;

    /**
     * Atribuição do valor 4 à variável x.
     *
     *  x -> 4
     *  y -> 0
     *  p -> endereço de y
     * *p -> 0
     */
    x = 4;

    /**
     * Incremento do valor armazenado no endereço apontado por p em 1.
     *
     *  x -> 4
     *  y -> 1
     *  p -> endereço de y
     * *p -> 1
     */
    (*p)++;

    /**
     *  Decremento do valor armazenado na variável x em 1.
     *
     *  x -> 3
     *  y -> 1
     *  p -> endereço de y
     * *p -> 1
     */
    --x;

    /**
     *  Atribuição da soma entre o valor armazenado no endereço apontado por p
     *  e o valor armazenado na variável x ao endereço apontado por p.
     *
     *  x -> 3
     *  y -> 4
     *  p -> endereço de y
     * *p -> 4
     */
    (*p) += x;

    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("p = %d\n", p);
    printf("*p = %d\n", *p);

    return 0;
}