#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float mi = 0, km = 0;

    printf("Informe a distancia (mi): ");
    scanf("%f", &mi);

    km = 1.61 * mi;

    printf("\n\n%.3fmi = %.3fkm", mi, km);

    printf("\n\n");
    system("pause");
    return 0;
}
