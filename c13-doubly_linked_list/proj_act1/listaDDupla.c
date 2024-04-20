#include <stdio.h>
#include <stdlib.h>
#include "listaDDupla.h"

typedef struct elemento{
    struct elemento *ant;
    struct elemento *prox;
    ALUNO dados;
}Elem;

Lista *criaLista()
{
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
    {
        *li = NULL;
    }
    return li;
}

int tamanho_lista(Lista *li)
{
    if(li == NULL)
    {
        return 0;
    }
    int acum = 0;
    Elem *no = *li;
    while(no != NULL)
    {
        acum++;
        no = no->prox;
    }
    return acum;
}

int lista_cheia(Lista *li)
{
    return 0;
}

int lista_vazia(Lista *li)
{
    if(li == NULL)
    {
        return 1;
    }
    if(*li == NULL)
    {
        return 1;
    }
    return 0;
}

int insere_lista_inicio(Lista *li, ALUNO al)
{
    if(li == NULL){
        return 0;
    }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) {
        return 0;
    }
    no->dados = al;
    no->prox = (*li);
    no->ant = NULL;
    if(*li != NULL)
    {
        (*li)->ant = no;
    }
    *li = no;
    return 1;
}

int insere_lista_final(Lista *li, ALUNO al)
{
    if(li == NULL)
    {
        return 0;
    }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) {
        return 0;
    }
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){//lista vazia, insere no inicio
        no->ant = NULL;
        *li = no;
    }
    else
    {
        Elem *aux = *li;
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
    }
    return 1;
}

int insere_lista(Lista *li, ALUNO al)
{
    if(li == NULL){
        return 0;
    }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
    {
        return 0;
    }
    no->dados = al;
    if(lista_vazia(li)){//insere no inicio
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return 1;
    }
    else
    {
        Elem *anterior, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula)
        {
            anterior = atual;
            atual = atual->prox;
        }
        if(atual == *li){//insere no inicio
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
        }
        else
        { //insere em qualquer outra posicao
            no->prox = anterior->prox;
            no->ant = anterior;
            anterior->prox = no;
            if(atual != NULL)
            {
                atual->ant = no;
            }
        }
        return 1;
    }
}

int consulta_lista_pos(Lista *li, int pos, ALUNO *al)
{
    if(li == NULL || pos <= 0)
    {
        return 0;
    }
    Elem *no = *li;
    int i = 1;
    while(no != NULL && i < pos)
    {
        no = no->prox;
        i++;
    }
    if(no == NULL) //lista vazia ou não encontrou elemento
    {
        return 0;
    }
    else
    {
        *al = no->dados;
        return 1;
    }
}

int consulta_lista_mat(Lista *li, int mat, ALUNO *al)
{
    if(li == NULL)
    {
        return 0;
    }
    Elem *no = *li;
    while(no != NULL && no->dados.matricula != mat)
    {
        no = no->prox;
    }
    if(no == NULL){ //matricula nao encontrada
        return 0;
    }else{
      *al = no->dados;
      return 1;
    }
}

int remove_lista_inicio(Lista *li)
{
    if(li == NULL) //verifica se a lista existe
    {
        return 0;
    }
    if((*li) == NULL) //verifica se a lista esta vazia
    {
        return 0;
    }
    Elem *no = *li;
    *li = no->prox;
    if(no->prox != NULL)
    {
        no->prox->ant = NULL;
    }
    free(no);
    return 1;
}

int remove_lista_final(Lista *li)
{
    if(li == NULL) //verifica se a lista existe
    {
        return 0;
    }
    if(*li == NULL) //verifica se a lista esta vazia
    {
        return 0;
    }
    Elem *no = *li;
    while(no->prox != NULL) //Percorre lista até que o prox seja NULL
    {
        no = no->prox;
    }
    if(no->ant == NULL) //só existe o primeiro elemento?
    {
        *li = no->prox; //o proximo é NULL
    }
    else
    {
        no->ant->prox = NULL;
    }
    free(no);
    return 1;
}

int remove_lista(Lista *li, int mat)
{
    if(li == NULL) //verifica se a lista existe
    {
        return 0;
    }
    Elem *no = *li;
    while(no != NULL && no->dados.matricula != mat)
    {
        no = no->prox;
    }
    if(no == NULL) //Não encontrou matricula
    {
        return 0;
    }
    if(no->ant == NULL) //remover primeiro
    {
        *li = no->prox;
        //no->prox->ant = NULL;
    }
    else
    {
        no->ant->prox = no->prox; //remove no meio
    }
    if(no->prox != NULL)
    {
        no->prox->ant = no->ant; //remove o último
    }
    free(no);
    return 1;
}

void destroi_lista(Lista *li)
{
    if(li != NULL)
    {
        Elem *no;
        while((*li) != NULL)
        {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

