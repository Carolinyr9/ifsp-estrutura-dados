#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float celsius, fahrenheit;

    printf("Informe a temperatura (F): ");
    scanf("%f", &fahrenheit);

    celsius = (5 * (fahrenheit - 32))/9;

    printf("\n\nTemperatura em Celsius: %.1f^C", celsius);

    printf("\n\n");
    system("pause");
    return 0;
}
