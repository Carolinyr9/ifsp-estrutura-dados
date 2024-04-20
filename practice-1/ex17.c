#include <stdio.h>
#include <stdlib.h>

int main()
{
    float salariodia = 30, irpf = 0.08, pagamento;
    int diastrabalhados = 0;


    printf("Informe o numero de dias trabalhados: ");
    scanf("%d", &diastrabalhados);

    pagamento = salariodia * diastrabalhados * (1-irpf);

    printf("\nPagamento liquido para o encanador: R$ %.2f", pagamento);

    printf("\n\n");
    system("pause");
    return 0;
}
