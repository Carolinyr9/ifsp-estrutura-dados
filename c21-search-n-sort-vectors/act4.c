#include <stdio.h>

// Funcao para ordernar um vetor por cocktail sort/ shake sort (ordenacao oscilante)
void ordena_cocktailSort(int *vetor, int n)
{
    int i, continua, aux, fim = n - 1, inicio = 0;
    do
    {
        continua = 0;
        for (i = inicio; i < fim; i++)
        {
            if (vetor[i] > vetor[i + 1])
            {
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
                continua = i;
            }
        }
        fim--;
        for (i = fim; i > inicio; i--)
        {
            if (vetor[i] < vetor[i - 1])
            {
                aux = vetor[i];
                vetor[i] = vetor[i - 1];
                vetor[i - 1] = aux;
                continua = i;
            }
        }
        inicio++;
    } while (continua != 0);
}

void imprimirVetor(int *vetor, int n) {
    int i, fim = n - 1;
    for (i = 0; i < n; i++) {
        printf("%d", vetor[i]);
        if (i < fim) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int vetor[] = {120, 150, 110, 130, 100, 160, 140, 190, 180, 170};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor desordenado: ");
    imprimirVetor(vetor, tamanho);

    printf("\nOrdenando por metodo bubbleSort Oscilante - CocktailSort...\n");
    ordena_cocktailSort(vetor, tamanho);

    printf("\nVetor ja ordenado: ");
    imprimirVetor(vetor, tamanho);

    printf("\n\n");
    system("pause");
    return 0;
}

