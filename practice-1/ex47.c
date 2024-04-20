#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float kg = 0, lb = 0;

    printf("Informe a massa (lb): ");
    scanf("%f", &lb);

    kg = lb * 0.45;

    printf("\n\n%.3flb = %.3fkg", lb, kg);

    printf("\n\n");
    system("pause");
    return 0;
}
