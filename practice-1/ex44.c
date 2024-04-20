#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float m3 = 0, litros = 0;

    printf("Informe o volume (m^3): ");
    scanf("%f", &m3);

    litros = 1000 * m3;

    printf("\n\n%.1fm^3 = %.1fL", m3, litros);

    printf("\n\n");
    system("pause");
    return 0;
}
