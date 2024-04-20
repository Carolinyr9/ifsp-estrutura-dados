#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //Declarando variaveis
    int i;

    //Criando valor n
    unsigned int n = 0;

    //Pedindo valor n para usuario
    printf("Digite o numero de elementos que deseja para o vetor: ");
    scanf(" %d", &n);

    //Criando vetor de int com n posicoes
    int *v = (int*) calloc(n, sizeof(int));
    if(v == NULL)
    {
        printf("ERRO: Sem memoria suficiente para criar vetor!");
        exit(1); // Encerra a execucao sem sucesso (1)
    }

    //Povoando o vetor de n posicoes
    for(i = 0; i < n; i++)
    {
        v[i] = 0;
        while(v[i] % 2 == 0 || v[i] <= 0)
        {
            printf("\nDigite um numero INTEIRO IMPAR POSITIVO (%d/%d): ", i+1, n);
            scanf(" %d", &v[i]);
        }
    }

    //Imprimindo vetor para usuario
    system("cls");
    printf("\nVetor formado: [");
    for(i = 0; i < n; i++)
    {
        if(i == n-1)
            printf("%d];", v[i]);
        else
            printf("%d, ", v[i]);
    }

    //Libera a memoria alocada
    free(v);

    printf("\n\n\n");
    system("pause");
    return 0;
}
