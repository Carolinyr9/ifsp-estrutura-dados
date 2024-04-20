#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i = 0;
    unsigned int n = 0;

    //Pedindo valor n para usuario
    printf("Digite um numero natural: ");
    scanf(" %d", &n);

    //Alocando vetor de float dinamicamente
    float *v = (float*) calloc(n, sizeof(float));
    if(v == NULL)
    {
        printf("ERRO: Memoria insuficiente para criar vetor!");
        exit(1); // Encerra a execucao sem sucesso (1)
    }

    //Coletando valores e povoando vetor
    for(i = 0; i < n; i++)
    {
        printf("\nDigite o valor real na posicao (%d): ", i+1);
        scanf(" %f", &v[i]);
    }

    //Imprimindo valores do vetor
    system("cls");
    for(i = 0; i < n; i++)
    {
        printf("\nPosicao %2d = %.2f", i+1, v[i]);
    }

    //Libera a memoria alocada
    free(v);

    printf("\n\n\n");
    system("pause");
    return 0;
}
