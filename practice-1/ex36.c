#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float vKmH = 0, vMS = 0;

    printf("Informe a velocidade (km/h): ");
    scanf("%f", &vKmH);

    vMS = vKmH / 3.6;

    printf("\n\n%.2fkm/h = %.2fm/s", vKmH, vMS);

    printf("\n\n");
    system("pause");
    return 0;
}
