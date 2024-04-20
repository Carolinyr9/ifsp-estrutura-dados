// Caroliny Rocha Sampaio GU3046532
// J�ssica Bueno Ramos GU3046346

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "projetoFinal.h"

int main()
{

    Lista *li; // ponteiro para ponteiro que est� no arquivo listaLigada.h
    li = criaLista();

    CLIENTE cli;

    pegaClientesArquivo(li, &cli);

    FILE *f;
    f = fopen("projetoAcme.txt", "wb");

    if(f == NULL){ // Garante que o arquivo foi aberto corretamente
        printf("\t\tErro ao abrir o arquivo!\n\n");
        system("pause");
        exit(1);
    }

    // Vari�vel a seguir criadas para a busca:
    int codigo = 0;

    menu(codigo, li); // Chama a fun��o que gera o looping menu
    gravaArquivo(li, f); // Grava a lista no arquivo

    fclose(f);
    return 0;
}
