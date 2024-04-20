#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char num[4];

    printf("Digite um numero de quatro digitos: ");
    scanf("%s", &num);

    printf("\n%c\n%c\n%c\n%c", num[0], num[1], num[2], num[3]);

    printf("\n\n");
    system("pause");
    return 0;
}
