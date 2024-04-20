#include <stdio.h>

// Funcao para ordenar um vetor por insertion sort
void ordena_insertionSort(int *vetor, int n)
{
    int i, j, aux;
    for (i = 1; i < n; i++)
    {
        aux = vetor[i];
        for (j = i; (j > 0) && (aux < vetor[j - 1]); j--)
        {
            vetor[j] = vetor[j - 1];
        }
        vetor[j] = aux;
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

    printf("\nOrdenando por metodo insertionSort...\n");
    ordena_insertionSort(vetor, tamanho);

    printf("\nVetor ja ordenado: ");
    imprimirVetor(vetor, tamanho);

    printf("\n\n");
    system("pause");
    return 0;
}

