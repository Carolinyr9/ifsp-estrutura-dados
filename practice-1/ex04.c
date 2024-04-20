#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num;

    printf("Digite um numero real: ");
    scanf("%f", &num);

    printf("\n\nA quinta parte de %.2f e: %.2f", num, num*1/5);

    printf("\n\n");
    system("pause");
    return 0;
}
