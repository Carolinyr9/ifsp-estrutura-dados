#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float sqr(float x)
{
    return pow(x, 0.5);
}

int main()
{
    float a, b, h;

    printf("Digite o valor do cateto a: ");
    scanf("%f", &a);
    printf("Digite o valor do cateto b: ");
    scanf("%f", &b);

    h = sqr(pow(a, 2) + pow(b, 2));

    printf("\nUm triangulo retangulo de catetos %.2f e %.2f tem a hipotenusa: %.2f", a, b, h);

    printf("\n\n");
    system("pause");
    return 0;
}
