#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void somaCem(int *v);

int main()
{
    int v1, v2, v3, *p_v1, *p_v2, *p_v3;

    printf("Digite um valor inteiro: ");
    scanf(" %d", &v1);
    printf("Digite outro valor inteiro: ");
    scanf(" %d", &v2);
    printf("Digite mais um valor inteiro: ");
    scanf(" %d", &v3);

    p_v1 = &v1;
    p_v2 = &v2;
    p_v3 = &v3;

    somaCem(p_v1);
    somaCem(p_v2);
    somaCem(p_v3);

    printf("\n\nValores + 100:");
    printf("\n\tValor 1= %d", v1);
    printf("\n\tValor 2= %d", v2);
    printf("\n\tValor 3= %d", v3);

    printf("\n\n");
    system("pause");
    return 0;
}

void somaCem(int *v)
{
    *v += 100;
}
