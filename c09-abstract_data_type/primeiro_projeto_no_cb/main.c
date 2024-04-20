#include <stdio.h>
#include <stdlib.h>
#include "my_lib.h"

int main()
{
    int n;
    printf("Entre com um numero inteiro: ");
    scanf(" %d", &n);

    printf("Versao iterativa:\n");
    gauss_iterativa(n);
    printf("\n\n");
    printf("Versao recursiva:\n");
    gauss_recursiva(n);

    printf("\n\n\n");
    system("pause");
    return 0;
}
