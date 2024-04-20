#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float celsius, kelvin;

    printf("Informe a temperatura (K): ");
    scanf("%f", &kelvin);

    celsius = kelvin - 273.15;

    printf("\n\nTemperatura em Celsius: %.1f^C", celsius);

    printf("\n\n");
    system("pause");
    return 0;
}
