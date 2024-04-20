#include <stdio.h>

// Funcao para busca linear em um vetor desordenado
int buscaLinear(int *vetor, int n, int elem) 
{
    int i;
    for (i = 0; i < n; i++) 
    {
        if (vetor[i] == elem) 
        {
            return i;
        }
    }
    return -1; // Retorna -1 se a chave nao foi encontrada
}

// Funcao para busca ordenada em um vetor ordenado
int buscaOrdenada(int *vetor, int n, int elem) {
    int i;
    for (i = 0; i < n; i++) 
    {
        if (vetor[i] == elem)
        {
            return i;
        } 
        else if(vetor[i] > elem)
        {
            break;
        }
    }
    return -1;
}

// Funcao para busca binaria em um vetor ordenado
int buscaBinaria(int *vetor, int n, int elem)
{
    int i, meio, inicio = 0, fim = n - 1;

    while (inicio <= fim) 
    {
        meio = (inicio + fim) / 2;

        printf("Inicio: %d\tFim: %d\n\n", inicio, fim);

        if (elem < vetor[meio]) 
        {
            fim = meio - 1; // busca na metade esquerda
        } 
        else if (elem > vetor[meio])
        {
            inicio = meio + 1; // busca na metade direita
        } 
        else
        {
            return meio;
        }
    }
    return -1;
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
    int vetorDesordenado[] = {120, 150, 110, 130, 100, 160, 140, 190, 180, 170};
    int tamanhoDesordenado = sizeof(vetorDesordenado) / sizeof(vetorDesordenado[0]);
    int elemDesordenado = 100;

    int vetorOrdenado[] = {100, 110, 120, 130, 140, 150, 160, 170, 180, 190};
    int tamanhoOrdenado = sizeof(vetorOrdenado) / sizeof(vetorOrdenado[0]);
    int elemOrdenado = 170;
    int elemBinaria = 130;

    // Busca Linear
    printf("Vetor: ");
    imprimirVetor(vetorDesordenado, tamanhoDesordenado);

    printf("\nElemento a ser procurado por busca linear: %d\n\n", elemDesordenado);

    int resultadoLinear = buscaLinear(vetorDesordenado, tamanhoDesordenado, elemDesordenado);
    if (resultadoLinear != -1) {
        printf("A posicao do elemento no vetor e: %d\n\n\n", resultadoLinear);
    } else {
        printf("Busca Linear: Elemento %d nao encontrado no vetor desordenado.\n", elemDesordenado);
    }

    // Busca Ordenada
    printf("Vetor Ordenado: ");
    imprimirVetor(vetorOrdenado, tamanhoOrdenado);

    printf("\nElemento a ser procurado por busca ordenada: %d\n\n", elemOrdenado);

    int resultadoOrdenado = buscaOrdenada(vetorOrdenado, tamanhoOrdenado, elemOrdenado);
    if (resultadoOrdenado != -1) {
        printf("A posicao do elemento no vetor e: %d\n\n", resultadoOrdenado);
    } else {
        printf("Busca Ordenada: Elemento %d nao encontrada no vetor ordenado.\n", elemOrdenado);
    }

    // Busca Binaria
    printf("\nElemento a ser procurado por busca binaria: %d\n\n", elemBinaria);

    int resultadoBinaria = buscaBinaria(vetorOrdenado, tamanhoOrdenado, elemBinaria);
    if (resultadoBinaria != -1) {
        printf("\nA posicao do elemento no vetor e: %d\n\n", resultadoBinaria);
    } else {
        printf("Busca Binaria: Elemento %d nao encontrada no vetor ordenado.\n", elemBinaria);
    }

    printf("\n\n");
    system("pause");
    return 0;
}

