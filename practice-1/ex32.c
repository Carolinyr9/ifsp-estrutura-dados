#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float celsius, fahrenheit;

    printf("Informe a temperatura (^C): ");
    scanf("%f", &celsius);

    fahrenheit = celsius * (9/5) + 32;

    printf("\n\nTemperatura em Fahrenheit: %.1fF", fahrenheit);

    printf("\n\n");
    system("pause");
    return 0;
}
