#include <stdio.h>

// Funcao para ordenar um vetor por selection sort
void ordena_selectionSort(int *vetor, int n)
{
    int i, j, menor, aux;
    for (i = 0; i < n - 1; i++)
    {
        menor = i;
        for (j = i + 1; j < n; j++)
        {
            if (vetor[j] < vetor[menor])
            {
                menor = j;
            }
        }
        if (i != menor)
        {
            aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }
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

    printf("\nOrdenando por metodo selectionSort...\n");
    ordena_selectionSort(vetor, tamanho);

    printf("\nVetor ja ordenado: ");
    imprimirVetor(vetor, tamanho);

    printf("\n\n");
    system("pause");
    return 0;
}

