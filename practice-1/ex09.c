#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, dobro, triplo, imprimir;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    dobro = num * 2;
    triplo = num * 3;
    imprimir = (triplo+1)+(dobro-1);

    printf("\n%d", imprimir);

    printf("\n\n");
    system("pause");
    return 0;
}
