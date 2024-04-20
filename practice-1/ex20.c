#include <stdio.h>
#include <stdlib.h>

int main()
{
    float total = 0,
        totalcomdesconto = 0.9,
        parcelamento,
        comissao = 0.05,
        comissaoparcelada = 0.05;

    printf("Informe o valor total: ");
    scanf("%f", &total);

    totalcomdesconto *= total;
    parcelamento = total / 3;
    comissao *= totalcomdesconto;
    comissaoparcelada *= total;

    printf("\nTotal (Desconto de 10 porcento): R$ %.2f", totalcomdesconto);
    printf("\nValor parcela em 3x sem juros: R$ %.2f", parcelamento);
    printf("\n\n\tComissao Vendedor a vista: R$ %.2f", comissao);
    printf("\n\tComissao Vendedor parcelado: R$ %.2f", comissaoparcelada);

    printf("\n\n");
    system("pause");
    return 0;
}
