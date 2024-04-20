#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //Declarando variaveis
    int i = 0;
    float media = 0, soma = 0;

    //Criando valor n
    unsigned int n = 0;

    //Pedindo valor n para usuario
    printf("Digite o numero de alunos que ha na turma: ");
    scanf(" %d", &n);

    //Criando vetor de int com n posicoes
    float *v = (float*) calloc(n, sizeof(float));
    if(v == NULL)
    {
        printf("ERRO: Sem memoria suficiente para criar vetor!");
        exit(1); // Encerra a execucao sem sucesso (1)
    }

    //Povoando o vetor com as notas dos alunos
    for(i = 0; i < n; i++)
    {
        printf("\nDigite a nota do aluno (%d): ", i+1);
        scanf(" %f", &v[i]);
    }

    //Imprimindo as notas dos alunos
    system("cls");
    for(i = 0; i < n; i++)
    {
        printf("\nO aluno %2d tirou %2.1f!", i+1, v[i]);
    }

    //Calculando a media da sala
    for(i = 0; i < n; i++)
    {
        soma += v[i];
    }
    media = soma / n;

    //Imprimindo a media
    printf("\n\nA media de nota da sala e: %.1f", media);

    //Libera a memoria alocada
    free(v);

    printf("\n\n\n");
    system("pause");
    return 0;
}
