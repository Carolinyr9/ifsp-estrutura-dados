#include <stdio.h>
#include <stdlib.h>
#include "filaD.h"

int main()
{
    int x; // para os codigos de erros
    ALUNO al, al1, al2, al3;
    Fila *fi;
    
    fi = cria_fila();

    al1.matricula = 100;
    al1.n1 = 8.3;
    al1.n2 = 8.4;
    al1.n3 = 8.5;

    al2.matricula = 110;
    al2.n1 = 7.3;
    al2.n2 = 7.4;
    al2.n3 = 7.5;

    al3.matricula = 120;
    al3.n1 = 6.3;
    al3.n2 = 6.4;
    al3.n3 = 6.5;

    x = tamanho_fila(fi);
    printf("\nO tamanho da fila e %d", x);


    x = fila_cheia(fi);
    if(x){
        printf("\nA fila esta cheia!");
    }else {
        printf("\nA fila nao esta cheia");
    }

    x = fila_vazia(fi);
    if(x){
        printf("\nA fila esta vazia!");
    }else {
        printf("\nA fila nao esta vazia");
    }

    x = insere_fila(fi, al1);
    if(x){
        printf("\nElemento inserido com sucesso!");
    } else {
        printf("\nErro, elemento nao inserido.");
    }

    x = insere_fila(fi, al2);
    if(x){
        printf("\nElemento inserido com sucesso!");
    } else {
        printf("\nErro, elemento nao inserido.");
    }

    x = insere_fila(fi, al3);
    if(x){
        printf("\nElemento inserido com sucesso!");
    } else {
        printf("\nErro, elemento nao inserido.");
    }

    x = remove_fila(fi);
    if(x){
        printf("\nElemento removido com sucesso!");
    } else {
        printf("\nErro, elemento nao removido.");
    }

    x = consulta_fila(fi, &al);
    if(x){
        printf("\nConsulta realizada com sucesso: ");
        printf("\nMatricula: %d", al.matricula);
        printf("\nNota 1: %.2f", al.n1);
        printf("\nNota 2: %.2f", al.n2);
        printf("\nNota 3: %.2f", al.n3);
    }else {
        printf("\nErro, consulta nao realizada.");
    }

    destroi_fila(fi);

    printf("\n\n");
    system("pause");
    return 0;
}
