#include <stdio.h>
#include <stdlib.h>

int main()
{
    // declaracao da matriz com 5 linhas e 5 colunas
    int mtrx[5][5], v[10];
    int i = 0, j = 0, soma = 0;

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            printf("Digite os valores da matriz na posicao: %d e %d: ", i, j);
            //efetua a leitura de todos os campos da matriz
            scanf("%d", &mtrx[i][j]);
        }
    }

    // Soma as linhas da matriz, percorre por todas as colunas através do "j" e por todas as linhas através do "i".
    printf("\n\nTotal por linha:\n\n");
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
                soma = soma + mtrx[i][j];
        }
        printf("\tLinha %d: soma = %d\n\n", i +1, soma);
        v[i] = soma;
        soma = 0;
    }

    // Soma as colunas da matriz, percorre por todas as linhas através do "i" e por todas as colunas através do "j".
    soma = 0;
    printf("Total por coluna: \n\n");

    for(j = 0; j < 5; j++)
    {
        for(i = 0; i < 5; i++)
        {
                soma = soma + mtrx[i][j];
        }
        printf("\tColuna %d: soma = %d\n\n", j + 1, soma);
        v[j+5] = soma;
        soma = 0;
    }

    // Totalizacao linhas e colunas

    for(i = 0; i <5; i++)
    {
        printf("\nOs valores da soma da linha %d sao: %d\n", i + 1, v[i]);
        printf("\nOs valores da soma da coluna %d sao: %d\n", i + 1, v[i + 5]);
    }


    // Exibir matrix
    printf("\n\nMatrix formada:\n\n");
	for (i = 0; i < 5; i++)
    {
    	for (j = 0; j < 5; j++)
    	{
        	printf("\t %d ", mtrx[i][j]);
    	}
        printf("\n");
	}

    printf("\n\n\n");
    system("pause");
    return 0;
}
