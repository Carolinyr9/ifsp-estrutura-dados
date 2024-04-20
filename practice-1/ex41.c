#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float graus = 0, rad = 0, pi = 3.141592;

    printf("Informe o angulo (rad): ");
    scanf("%f", &rad);

    graus = rad * 180 / pi;

    printf("\n\n%.2frad = %.2f^", rad, graus);

    printf("\n\n");
    system("pause");
    return 0;
}
