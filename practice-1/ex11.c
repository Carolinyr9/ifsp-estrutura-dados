#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float raio, area, pi = 3.141592;

    printf("Digite o raio do circulo: ");
    scanf("%f", &raio);

    area = pi * pow(raio, 2);

    printf("\nA area de um circulo de raio %f e: %f", raio, area);

    printf("\n\n");
    system("pause");
    return 0;
}
