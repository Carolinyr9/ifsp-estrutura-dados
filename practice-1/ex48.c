#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float yd = 0, m = 0;

    printf("Informe o comprimento em jardas (yd): ");
    scanf("%f", &yd);

    m = 0.91 * yd;

    printf("\n\n%.3fyd = %.3fm", yd, m);

    printf("\n\n");
    system("pause");
    return 0;
}
