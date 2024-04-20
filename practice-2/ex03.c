#include <stdio.h>
#include <stdlib.h>

void somaDiagonais(int a[6][6], int *p, int *s);

int main()
{
    int i, j, linhas = 6, colunas = 6;
    int matriz[linhas][colunas];
    int somaPrincipal = 0, somaSegundaria = 0;

    //Preenchendo matriz
    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            printf("Digite o valor inteiro da matriz na posicao: %d e %d: ", i+1, j+1);
            //efetua a leitura de todos os campos da matriz
            scanf("%d", &matriz[i][j]);
        }
    }

    somaDiagonais(matriz, &somaPrincipal, &somaSegundaria);

    printf("\n\nSoma Diagonal\n\t\tPrincipal: %d\n\t\tSecundaria: %d", somaPrincipal, somaSegundaria);

    printf("\n\n\n");
    system("pause");
    return 0;
}

void somaDiagonais(int a[6][6], int *p, int *s)
{

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(i == j)
            {
                *p += a[i][j];
            }
            switch(i)
            {
                case 0:
                    if(j == 5)
                        *s += a[i][j];
                break;
                case 1:
                    if(j == 4)
                        *s += a[i][j];
                break;
                case 2:
                    if(j == 3)
                        *s += a[i][j];
                break;
                case 3:
                    if(j == 2)
                        *s += a[i][j];
                break;
                case 4:
                    if(j == 1)
                        *s += a[i][j];
                break;
                case 5:
                    if(j == 0)
                        *s += a[i][j];
                break;
                default:
                    break;

            }
        }
    }
}
