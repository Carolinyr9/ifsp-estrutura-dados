#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float celsius, kelvin;

    printf("Informe a temperatura (C): ");
    scanf("%f", &celsius);

    kelvin = celsius + 273.15;

    printf("\n\nTemperatura em Celsius: %.1fK", kelvin);

    printf("\n\n");
    system("pause");
    return 0;
}
