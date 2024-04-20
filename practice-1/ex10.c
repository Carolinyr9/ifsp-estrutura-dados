#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float lado, area;

    printf("Digite o tamanho do lado de um quadrado: ");
    scanf("%f", &lado);

    area = pow(lado, 2);

    printf("\nA area de um quadrado de lado %.2f e: %.2f", lado, area);

    printf("\n\n");
    system("pause");
    return 0;
}
