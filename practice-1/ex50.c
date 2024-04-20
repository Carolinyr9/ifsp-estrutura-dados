#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float m2 = 0, ac = 0;

    printf("Informe o comprimento (m^2): ");
    scanf("%f", &m2);

    ac = m2 * 0.000247;

    printf("\n\n%.2fm^2 = %.2facres", m2, ac);

    printf("\n\n");
    system("pause");
    return 0;
}
