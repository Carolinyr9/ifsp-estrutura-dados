#include <stdio.h>
#include <stdlib.h>

int main()
{
    float h, raio, volume, pi = 3.141592;

    printf("Informe a altura do cilindro: ");
    scanf("%f", &h);
    printf("Informe o raio do cilindro: ");
    scanf("%f", &raio);

    volume = pi * (raio * raio) * h;

    printf("\nO volume de um clindro de altura %.2f e raio %.2f e: %.2f", h, raio, volume);

    printf("\n\n");
    system("pause");
    return 0;
}
