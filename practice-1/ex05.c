#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double v1, v2, v3, quadrados;

    printf("Digite um numero: ");
    scanf("%lf", &v1);
    printf("Digite outro numero: ");
    scanf("%lf", &v2);
    printf("Digite mais um numero: ");
    scanf("%lf", &v3);

    quadrados = pow(v1, 2) + pow(v2, 2) + pow(v3, 2);

    printf("\n\nA soma dos quadrados dos tres valores lidos e %.lf", quadrados);

    printf("\n\n");
    system("pause");
    return 0;
}
