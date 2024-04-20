#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char maiuscula, minuscula = 32;

    printf("Digite uma letra maiuscula: ");
    scanf("%c", &maiuscula);

    minuscula += maiuscula;

    printf("\nConvertido em minuscula: %c", minuscula);

    printf("\n\n");
    system("pause");
    return 0;
}
