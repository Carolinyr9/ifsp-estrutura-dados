#include <stdio.h>
#include <stdlib.h>

int main()
{
    float valor, cotacaodolar, valoremdolar;

    printf("Digite um valor (R$): ");
    scanf("%f", &valor);
    printf("Digite quantos reais esta custando US$1 (R$): ");
    scanf("%f", &cotacaodolar);

    valoremdolar = valor/cotacaodolar;

    printf("\nO valor R$%.2f correponde a US$%.2f", valor, valoremdolar);

    printf("\n\n");
    system("pause");
    return 0;
}
