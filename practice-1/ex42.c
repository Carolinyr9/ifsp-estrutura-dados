#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float inch = 0, cm = 0;

    printf("Informe o comprimento (in): ");
    scanf("%f", &inch);

    cm = inch * 2.54;

    printf("\n\n%.2fin = %.2fcm", inch, cm);

    printf("\n\n");
    system("pause");
    return 0;
}
