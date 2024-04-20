#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float inch = 0, cm = 0;

    printf("Informe o comprimento (cm): ");
    scanf("%f", &cm);

    inch = cm / 2.54;

    printf("\n\n%.2fcm = %.2fin", cm, inch);

    printf("\n\n");
    system("pause");
    return 0;
}
