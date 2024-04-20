#include <stdio.h>
#include <stdlib.h>

void regressiva_iterativa(int n);
void regressiva_recursiva(int n);

int main()
{
    int n;

    printf("Entre com numero positivo: ");
    scanf("%d", &n);

    printf("\nVersao iterativa: \n\n");
    regressiva_iterativa(n);

    printf("\nVersao recursiva: \n\n");
    regressiva_recursiva(n);

    printf("\n\n");
    system("pause");
    return 0;
}

void regressiva_iterativa(int n)
{
    while(n >= 0)
    {
        printf("%d\n", n);
        n--;
    }
}

void regressiva_recursiva(int n)
{
    printf("%d\n", n);
    if(n > 0)
    {
        regressiva_recursiva(n-1);
    }

}

