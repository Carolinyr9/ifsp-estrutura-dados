#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float kg = 0, lb = 0;

    printf("Informe a massa (kg): ");
    scanf("%f", &kg);

    lb = kg / 0.45;

    printf("\n\n%.3fkg = %.3flb", kg, lb);

    printf("\n\n");
    system("pause");
    return 0;
}
