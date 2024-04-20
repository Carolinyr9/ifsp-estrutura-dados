#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    printf("Informe um valor inteiro: ");
    scanf("%d", &a);

    int *b = &a;
    int **c = &b;
    int ***d = &c;

    printf("\n\n");

    printf("\n    Dobro= %d", *b * 2);
    printf("\n   Triplo= %d", **c * 3);
    printf("\nQuadruplo= %d", ***d * 4);

    printf("\n\n");
    system("pause");
    return 0;
}

