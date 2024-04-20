#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v[5];
    int *p_v;

    p_v = v;

    for(int i = 0; i < 5; i++)
    {
        printf("Digite um inteiro para a posicao %d do array: ", i+1);
        scanf(" %d", &p_v[i]);
    }

    printf("\n\n");

    for(int i = 0; i < 5; i++)
    {
        printf("Dobro do inteiro na posicao %d do array: %d\n", i+1, p_v[i] * 2);
    }

    printf("\n\n");
    system("pause");
    return 0;
}

