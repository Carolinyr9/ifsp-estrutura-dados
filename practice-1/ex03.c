#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num;

    printf("Digite um numero real: ");
    scanf("%f", &num);

    printf("\n O quadrado de %.2f e: %.2f", num, num*num);

    printf("\n\n");
    system("pause");
    return 0;
}
