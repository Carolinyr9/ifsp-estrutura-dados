#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void somaCem(int *v);

int main()
{
    float vetorF[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    double vetorD[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};


    printf("Endereco Vetor de Float: ");
    for(int i = 0; i < 10; i++)
    {
        printf("\n\tPosicao %2d: %p", i+1, &vetorF[i]);
    }

    printf("\n\nEndereco Vetor de Double: ");
    for(int i = 0; i < 10; i++)
    {
        printf("\n\tPosicao %2d: %p", i+1, &vetorD[i]);
    }

    printf("\n\n");
    system("pause");
    return 0;
}

void somaCem(int *v)
{
    *v += 100;
}
