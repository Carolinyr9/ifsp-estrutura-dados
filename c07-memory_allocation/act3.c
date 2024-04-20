#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("~~~~~~~~SOMADOR DE MATRIZES HARDCORE~~~~~~~~\n");

    //Declarando variaveis
    int i = 0, j = 0, linhas = 0, colunas = 0;
    int **matriz1, **matriz2;

    //Pedindo o numero de linhas e colunas para o usuario
    printf("\nDigite o numero de linhas: ");
    scanf(" %d", &linhas);
    printf("\nDigite o numero de colunas: ");
    scanf(" %d", &colunas);

    //Criando primeira dimensao da matriz1
    matriz1 = (int**) malloc(linhas * sizeof(int*));
        //Verifica se alocacao teve sucesso
        if(matriz1 == NULL)
        {
            printf("ERRO: Sem memoria suficiente para a obra de arte!");
            exit(1); // Encerra a execucao sem sucesso (1)
        }

    //Criando segunda dimensao da matriz1
    for(i = 0; i < linhas; i++)
    {
        matriz1[i] = (int*) malloc(colunas * sizeof(int));
            //Verifica se alocacao teve sucesso
            if(matriz1[i] == NULL)
            {
                printf("ERRO: Sem memoria suficiente para a obra de arte!");
                exit(1); // Encerra a execucao sem sucesso (1)
            }
    }

    //Criando primeira dimensao da matriz2
    matriz2 = (int**) malloc(linhas * sizeof(int*));
        //Verifica se alocacao teve sucesso
        if(matriz2 == NULL)
        {
            printf("ERRO: Sem memoria suficiente para a obra de arte!");
            exit(1); // Encerra a execucao sem sucesso (1)
        }

    //Criando segunda dimensao da matriz2
    for(i = 0; i < linhas; i++)
    {
        matriz2[i] = (int*) malloc(colunas * sizeof(int));
            //Verifica se alocacao teve sucesso
            if(matriz2[i] == NULL)
            {
                printf("ERRO: Sem memoria suficiente para a obra de arte!");
                exit(1); // Encerra a execucao sem sucesso (1)
            }
    }


    system("cls"); //limpando console


    //Povoando matriz1
    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            printf("Digite os valores da matriz 1 na posicao: %d e %d: ", i+1, j+1);
            scanf("%d", &matriz1[i][j]);
        }
    }


    system("cls"); //limpando console


    //Povoando matriz2
    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            printf("Digite os valores da matriz 2 na posicao: %d e %d: ", i+1, j+1);
            scanf("%d", &matriz2[i][j]);
        }
    }


    system("cls"); //limpando console


    // Exibir matrizes formadas
    printf("Matriz 1:\n\n");
	for (i = 0; i < linhas; i++)
    {
    	for (j = 0; j < colunas; j++)
    	{
        	printf(" %2d ", matriz1[i][j]);
    	}
    	printf("\n");
	}
	printf("\nMatriz 2:\n\n");
	for (i = 0; i < linhas; i++)
    {
    	for (j = 0; j < colunas; j++)
    	{
        	printf(" %2d ", matriz2[i][j]);
    	}
    	printf("\n");
	}

	// Exibir matriz de soma da matriz 1 e 2
	printf("\nMatriz 1 + Matriz 2:\n\n");
	for (i = 0; i < linhas; i++)
    {
    	for (j = 0; j < colunas; j++)
    	{
        	printf(" %2d ", matriz1[i][j] + matriz2[i][j]);
    	}
    	printf("\n");
	}

    //Libera a memoria alocada
    free(matriz1);
    free(matriz2);

    printf("\n\n\n");
    system("pause");
    return 0;
}
