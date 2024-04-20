#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float m3 = 0, litros = 0;

    printf("Informe o volume (L): ");
    scanf("%f", &litros);

    m3 = litros / 1000;

    printf("\n\n%.1fL = %.1fm^3", litros, m3);

    printf("\n\n");
    system("pause");
    return 0;
}
