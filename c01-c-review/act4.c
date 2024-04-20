#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declaração de vetores com 5 posições:
    int v1[5], v2[5];
    int i = 0, j = 0, haIguais = 0;

    // preenchendo vetor vetor v1
    for(i = 0; i < 5; i++)
    {
        printf("Informe o valor do elemento %d do vetor 1: ", i + 1);
        scanf("%d", &v1[i]);
    }
    printf("\n\n");

    // preenchendo vetor vetor v2
    for(j = 0; j < 5; j++)
    {
        printf("Informe o valor do elemento %d do vetor 2: ", j + 1);
        scanf("%d", &v2[j]);
    }
    printf("\n");


    // Exibindo o vetor 1
    printf("\t\tVetor 1\n\t\t");
    for(i = 0; i < 5; i++) {
        printf("%d ", v1[i]);
    }

    // Exibindo o vetor 2
    printf("\n\t\tVetor 2\n\t\t");
    for(j = 0; j < 5; j++)
    {
        printf("%d ", v2[j]);
    }
    printf("\n");

    // Comparando os arrays
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            // Exibir valores que são comuns nos dois vetores
            if(v1[i] == v2[j])
            {
                printf("\nValores iguais na posicao: %d e %d \n", i+1, j+1);
                haIguais = 1;
            }
        }
    }

    if(!haIguais)
    {
        printf("\nNao ha valores iguais entre os vetores");
    }

    printf("\n\n");
    system("pause");
    return 0;
}
