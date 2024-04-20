#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float vKmH = 0, vMS = 0;

    printf("Informe a velocidade (m/s): ");
    scanf("%f", &vMS);

    vKmH = vMS * 3.6;

    printf("\n\n%.2fm/s = %.2fkm/h", vMS, vKmH);

    printf("\n\n");
    system("pause");
    return 0;
}
