#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float graus = 0, rad = 0, pi = 3.141592;

    printf("Informe o angulo em graus: ");
    scanf("%f", &graus);

    rad = graus * pi / 180;

    printf("\n\n%.2f^ = %.2frad", graus, rad);

    printf("\n\n");
    system("pause");
    return 0;
}
