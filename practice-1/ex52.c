#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // ha = simbolo de hectares
    float m2 = 0, ha = 0;

    printf("Informe o area (m^2): ");
    scanf("%f", &m2);

    ha = m2 * 0.0001;

    printf("\n\n%.2fm^2 = %.2fha", m2, ha);

    printf("\n\n");
    system("pause");
    return 0;
}
