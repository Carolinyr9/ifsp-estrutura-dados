#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float yd = 0, m = 0;

    printf("Informe o comprimento (m): ");
    scanf("%f", &m);

    yd = m / 0.91;

    printf("\n\n%.3fm = %.3fyd", m, yd);

    printf("\n\n");
    system("pause");
    return 0;
}
