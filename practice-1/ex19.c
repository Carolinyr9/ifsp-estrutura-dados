#include <stdio.h>
#include <stdlib.h>

int main()
{
    float salariobase = 0, gratificacao = 0.05, imposto = 0.07, salarioliquido;

    printf("Informe o salario-base: ");
    scanf("%f", &salariobase);

    gratificacao *= salariobase;
    imposto *= salariobase;
    salarioliquido = salariobase + gratificacao - imposto;

    printf("\nSalario a receber: R$ %.2f", salarioliquido);

    printf("\n\n");
    system("pause");
    return 0;
}
