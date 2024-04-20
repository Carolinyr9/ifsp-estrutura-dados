#include <stdio.h>
#include <stdlib.h>
#include "listaSequencial.h"

struct aluno cria_aluno()
{
    ALUNO al;

    printf("\n\nInforme a matricula do aluno: ");
    scanf("%d", &al.matricula);
    printf("\nInforme a nota 1: ");
    scanf("%f", &al.n1);
    printf("\nInforme a nota 2: ");
    scanf("%f", &al.n2);
    printf("\nInforme a nota 3: ");
    scanf("%f", &al.n3);

    return al;
}

struct lista{
    int qtd;
    struct aluno dados[MAX];
};

Lista *cria_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    if(li != NULL){
        li ->qtd = 0;
    }
    return li;
}

int tamanho_lista(Lista *li){
    if(li == NULL)
    {
        return -1; //Erro
    }
    else
    {
        return li->qtd;
    }
}

int lista_cheia(Lista *li){
    if(li == NULL)
    {
        return -1; //Erro
    }
    else
    {
        return (li->qtd == MAX);
    }
}

int lista_vazia(Lista *li){
    if(li == NULL)
    {
        return -1; //Erro
    }
    else
    {
        return (li->qtd == 0);
    }
}

int insere_lista_final(Lista *li, struct aluno al){
    if(li == NULL)
    {
        return 0;
    }
    if(lista_cheia(li))
    {
        return 0;
    }
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}

int insere_lista_inicio(Lista *li, struct aluno al)
{
    if(li == NULL)
    {
        return 0;
    }
    if(lista_cheia(li))
    {
        return 0;
    }
    int i;
    for(i = li->qtd - 1; i >= 0; i--)
    {
        li->dados[i+1] = li->dados[i];
    }
    li->dados[0] = al;
    li->qtd++;
    return 1;
}

int insere_lista_ordenada(Lista *li, struct aluno al)
{
    if(li == NULL)
    {
        return 0;
    }
    if(lista_cheia(li))
    {
        return 0;
    }
    int k, i = 0;
    while(i < li->qtd && li->dados[i].matricula < al.matricula)
    {
        i++;
    }
    for(k = li->qtd - 1; k >= i; k--)
    {
        li->dados[k+1] = li->dados[k];
    }
    li->dados[i] = al;
    li->qtd++;
    return 1;
}

int remove_lista_final(Lista *li)
{
    if(li == NULL)
    {
        return 0;
    }
    if(li->qtd == 0)
    {
        return 0;
    }
    li->qtd--;
    return 1;
}

int remove_lista_inicio(Lista *li)
{
    if(li == NULL)
    {
        return 0;
    }
    if(li->qtd == 0)
    {
        return 0;
    }
    int k = 0;
    for(k = 0; k < li->qtd-1; k++)
    {
        li->dados[k] = li->dados[k+1];
    }
    li->qtd--;
    return 1;
}

int remove_lista(Lista *li, int matricula)
{
    if(li == NULL)
    {
        return 0;
    }
    if(li->qtd == 0)
    {
        return 0;
    }
    int k, i = 0;
    while(i < li->qtd && li->dados[i].matricula != matricula)
    {
        i++;
    }
    if(i == li->qtd)
    {
        return 0; //Elemento não encontrado!
    }
    for(k = i; k < li->qtd-1; k++)
    {
        li->dados[k] = li->dados[k+1];
    }
    li->qtd--;
    return 1;
}

int consulta_lista_pos(Lista *li, int pos, struct aluno *al)
{
    if(li == NULL || pos <= 0 || pos >= li->qtd)
    {
        return 0;
    }
    *al = li->dados[pos-1];
    return 1;
}

int consulta_lista_mat(Lista *li, int mat, struct aluno *al)
{
    if(li == NULL)
    {
        return 0;
    }
    int k, i = 0;
    while(i < li->qtd && li->dados[i].matricula != mat)
    {
        i++;
    }
    if(i == li->qtd)//elemento nao encontrado
    {
        return 0;
    }
    *al = li->dados[i];
    return 1;
}

void libera_lista(Lista *li)
{
    free(li);
}

