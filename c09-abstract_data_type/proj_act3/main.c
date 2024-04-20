#include <stdio.h>
#include <stdlib.h>
#include "operacoes.h"

int main()
{
    int loop = 1;
    float n1 = 0, n2 = 0;
    char c = 'c';

    do
    {
        printf("Digite um numero: ");
        scanf("%f", &n1);
        printf("Digite mais um numero: ");
        scanf("%f", &n2);

        printf("\n\nQual operacao voce deseja realizar?\n\t");
        printf("Digite 'S' para somar;\n\t");
        printf("Digite 'Z' para subtrair;\n\t");
        printf("Digite 'M' para multiplicar;\n\t");
        printf("Digite 'D' para dividir;\n\t");
        printf("Digite 'R' para ver o ultimo resultado obtido;\n\t");
        printf("Digite qualquer outra tecla para sair do programa;\n");
        printf("Escolha: ");
        scanf(" %c", &c);

        system("cls");

        switch(c)
        {
        case 's':
        case 'S':
            printf("%.2f + %.2f = %.2f", n1, n2, somar(n1, n2));
            break;
        case 'z':
        case 'Z':
            printf("%.2f - %.2f = %.2f", n1, n2, subtrair(n1, n2));
            break;
        case 'm':
        case 'M':
            printf("%.2f x %.2f = %.2f", n1, n2, multiplicar(n1, n2));
            break;
        case 'd':
        case 'D':
            printf("%.2f / %.2f = %.2f", n1, n2, dividir(n1, n2));
            break;
        case 'r':
        case 'R':
            printf("Resultado da ultima operacao: %.2f", ultimoResultado());
            break;
        default:
            loop = 0;
            break;
        }

        printf("\n\n");
    }
    while(loop);

    system("pause");
    return 0;
}
