#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char num[3];

    printf("Digite um numero de tres digitos: ");
    scanf("%s", &num);

    printf("\n%s invertido: %c%c%c", num, num[2], num[1], num[0]);

    printf("\n\n");
    system("pause");
    return 0;
}
