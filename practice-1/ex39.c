#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float mi = 0, km = 0;

    printf("Informe a distancia (km): ");
    scanf("%f", &km);

    mi = km / 1.61;

    printf("\n\n%.3fkm = %.3fmi", km, mi);

    printf("\n\n");
    system("pause");
    return 0;
}
