#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double notas[4], media, somaNotas;

    for(int i = 0; i < 4; i++)
    {
        printf("\nDigite a nota %d: ", i+1);
        scanf("%lf", &notas[i]);
        somaNotas += notas[i];
    }

    media = somaNotas / 4;

    printf("\n\nMedia= %.1lf", media);

    printf("\n\n");
    system("pause");
    return 0;
}
