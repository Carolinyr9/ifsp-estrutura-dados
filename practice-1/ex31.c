#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float comprimento = 0, largura= 0, preco = 0, custoTotal = 0;

    printf("Informe o comprimento (m): ");
    scanf("%f", &comprimento);
    printf("Informe a largura (m): ");
    scanf("%f", &largura);
    printf("Informe o preco do metro do arame: ");
    scanf("%f", &preco);

    custoTotal = 2 * (comprimento + largura) * preco;

    printf("\n\n custo para cercar este terreno: R$ %.2f", custoTotal);

    printf("\n\n");
    system("pause");
    return 0;
}
