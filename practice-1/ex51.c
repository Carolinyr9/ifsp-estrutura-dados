#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float m2 = 0, ac = 0;

    printf("Informe o comprimento (acres): ");
    scanf("%f", &ac);

    m2 = ac * 4048.58;

    printf("\n\n%.2facres = %.2fm^2", ac, m2);

    printf("\n\n");
    system("pause");
    return 0;
}
