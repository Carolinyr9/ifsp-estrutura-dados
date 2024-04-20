#include <stdio.h>
#include <stdlib.h>

int gauss_iterativa(int n);
int gauss_recursiva(int n);

int main()
{
    int n, choice = 0;
    char c;

    printf("Entre com numero positivo: ");
    scanf("%d", &n);

    while(choice == 0)
    {
        printf("Digite R para calcular a soma da gauss com a funcao recursiva ou I para iterativa: ");
        scanf(" %c", &c);
        switch(c)
        {
        case 'r':
        case 'R':
            choice = 1;
            break;
        case 'i':
        case 'I':
            choice = 2;
            break;
        default:
            choice = 0;
            break;
        }
    }

    if(choice == 1)
        printf("\n\nSoma de Gauss para o numero %d de forma recursiva e: %d", n, gauss_recursiva(n));
    else
        printf("\n\nSoma de Gauss para o numero %d de forma iterativa e: %d", n, gauss_iterativa(n));

    printf("\n\n");
    system("pause");
    return 0;
}

int gauss_iterativa(int n)
{
    int soma = 0;

    while(n > 0)
    {
        soma += n;
        n--;
    }

    return soma;
}

int gauss_recursiva(int n)
{
    if(n == 0)
        return 0;
    return (n + gauss_recursiva(n-1));

}

