#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h"

void print_insercao(int x);

int main() {
    int x; // sera usado como retorno
    ArvBin *raiz;

    raiz = cria_arvBin();

    if(vazia_arvBin(raiz))
    {
        printf("\nA arvore esta vazia.");
    }
    else
    {
        printf("\nA arvore possui elementos.");
    }

    x = altura_arvBin(raiz);
    printf("\n\nAltura da arvore: %d", x);

    x = totalNO_arvBin(raiz);
    printf("\n\nTotal de nos na arvore: %d", x);

    //Antes de insercao elementos
    preOrdem_arvBin(raiz);
    emOrdem_arvBin(raiz);
    posOrdem_arvBin(raiz);

    //Insercao de elementos
    int arr_inserir[] = {150, 110, 100, 130, 120, 140, 160};
    for(int i = 0; i < 7; i++)
    {
        x = insere_arvBin(raiz, arr_inserir[i]);
        print_insercao(x);
    }

    //Remocao
    x = remove_arvBin(raiz, 100);
    if(x)
    {
        printf("Elemento 100 removido!");
    }
    else
    {
        printf("Nao foi possivel remover o elemento 100!");
    }

    //Pos insercao de elementos
    preOrdem_arvBin(raiz);
    emOrdem_arvBin(raiz);
    posOrdem_arvBin(raiz);

    //Consulta
    printf("\nBusca na Arvore Binaria:\n");
    if(consulta_arvBin(raiz, 140))
    {
        printf("\nConsulta realizada com sucesso!");
    }
    else
    {
        printf("\nElemento nao encontrado...");
    }

    liberar_arvBin(raiz);
    printf("\n\n");
    system("pause");
    return 0;
}

void print_insercao(int x)
{
    if(x)
    {
        printf("\n\nElemento inserido na arvore com sucesso.");
    }
    else
    {
        printf("\n\nErro: Elemento nao inserido na arvore.");
    }
}
