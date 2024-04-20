#include <stdio.h>
#include <stdlib.h>

int main()
{
    float preco;

    printf("Informe o valor do produto: ");
    scanf("%f", &preco);

    printf("Novo valor com 12 porcento de desconto: %.2f", preco * 0.88);

    printf("\n\n");
    system("pause");
    return 0;
}
