#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h"

struct NO {
    // cria estrutura de cada v�rtice da arv�re
    // no estilo lista encadeada
    int info;
    struct NO *esq;
    struct NO *dir;
};

ArvBin *cria_arvBin(){
    // ponteiro para arvore e aloca��o de m�moria
    ArvBin *raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL){
        // se dar certo, fica nula, j� que ainda n�o temos elementos
        *raiz = NULL;
    }
    return raiz;
}

void liberar_arvBin(ArvBin *raiz)
{
    if(raiz == NULL)
    {
        return;
    }
    libera_NO(*raiz); // percorre a �rvore e libera cada n�
    free(raiz); // libera a raiz
}

void libera_NO(struct NO *no) // fun��o recursiva
{
    if(no == NULL) // se n�o tiver filhos, retorna para o chamada anterior
    {
        return;
    }
    libera_NO(no->esq); // vai at� o n� folha da esquerda
    libera_NO(no->dir); // vai at� o n� folha da direita
    free(no);
    no = NULL;
}

int vazia_arvBin(ArvBin *raiz)
{
    if(raiz == NULL) // se a raiz estiver nula
    {
        return 1;
    }
    if(*raiz == NULL) // se o conte�do da raiz estiver nulo
    {
        return 1;
    }
    return 0;
}

int altura_arvBin(ArvBin *raiz) // fun��o recursiva
{
    // verifica se a arvore tem elementos e foi criada com sucesso
    if(raiz == NULL)
    {
        return 0;
    }
    if(*raiz == NULL)
    {
        return 0;
    }

    // vai descendo at� os n�-folhas
    int alt_esq = altura_arvBin(&((*raiz)->esq));
    int alt_dir = altura_arvBin(&((*raiz)->dir));
    if(alt_esq > alt_dir) // verifica qual n� terminal est� mais baixo
    {
        return(alt_esq + 1);
    }
    else
    {
        return(alt_dir + 1);
    }
}

int totalNO_arvBin(ArvBin *raiz)
{
    if(raiz == NULL)
    {
        return 0;
    }
    if(*raiz == NULL)
    {
        return 0;
    }
    int alt_esq = totalNO_arvBin(&((*raiz)->esq)); // passamos os endere�os dos n�s
    int alt_dir = totalNO_arvBin(&((*raiz)->dir));
    // n�mero de n�s da esquerda, n�meros de n�s da direita mais a raiz
    return(alt_esq + alt_dir + 1);
}

void preOrdem_arvBin(ArvBin *raiz)
{
    // visita a raiz, o filho da esquerda e o filho da direita
    if(raiz == NULL)
    {
        return;
    }
    if(*raiz != NULL)
    {
        printf("%d\n", (*raiz)->info);
        preOrdem_arvBin(&((*raiz)->esq));
        preOrdem_arvBin(&((*raiz)->dir));
    }
}

void emOrdem_arvBin(ArvBin *raiz)
{
    // visita da filho da esquerda, a raiz e por fim o filho da direita
    if(raiz == NULL)
    {
        return;
    }
    if(*raiz != NULL)
    {
        emOrdem_arvBin(&((*raiz)->esq));
        printf("%d\n", (*raiz)->info);
        emOrdem_arvBin(&((*raiz)->dir));
    }
}

void posOrdem_arvBin(ArvBin *raiz)
{
    // visita da filho da esquerda, o filho da direita e por fim a raiz
    if(raiz == NULL)
    {
        return;
    }
    if(*raiz != NULL)
    {
        emOrdem_arvBin(&((*raiz)->esq));
        emOrdem_arvBin(&((*raiz)->dir));
        printf("%d\n", (*raiz)->info);
    }
}

int insere_arvBin(ArvBin *raiz, int valor)
{
    if(raiz == NULL) // verifica se a �rvore � v�lida
    {
        return 0;
    }
    struct NO *novo; // alocando um novo n�
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL) // aloca��o deu errado
    {
        return 0;
    }

    // filhos ficam nulos
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;
    if(*raiz == NULL) // se a �rvore estiver vazia
    {
        *raiz = novo;
    }
    else // percorre os n�s para saber onde ele se encaixa
    {
        // auxiliares criados:
        struct NO *atual = *raiz;
        struct NO *ant = NULL;
        while(atual != NULL) // enquanto n�o chegar ao fim da �rvore
        {
            ant = atual;
            if(valor == atual->info)
            {
                free(novo); //Elemento ja existe!
                return 0;
            }

            if(valor > atual->info) // percorre elementos da direita agora
            {
                atual = atual->dir;
            }
            else // percorre elementos da direita agora
            {
                atual = atual->esq;
            }
        }
        if(valor > ant->info) // se o n� que queremos inserir tiver valor maior que seu pai
        {
            ant->dir = novo;
        }
        else
        {
            ant->esq = novo;
        }
    }
    return 1;
}

int remove_arvBin(ArvBin *raiz, int valor)
{
    if(raiz == NULL) // verifica se a �rvore � v�lida
    {
        return 0;
    }

    // auxiliares
    struct NO *ant = NULL;
    struct NO *atual = *raiz;
    while(atual != NULL) // percorre a �rvore at� o fim
    {
        if(valor == atual->info) // achou o elemento e faz o tratamento do lado removido
        {
            if(atual == *raiz) // verifica estamos na raiz
            {
                *raiz = remove_atual(atual);
            }
            else
            {
                if(ant->dir == atual) // verifica se est� na esquerda ou direita
                {
                    ant->dir = remove_atual(atual);
                }
                else
                {
                    ant->esq = remove_atual(atual);
                }
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->info) // procura nos filhos da direita
        {
            atual = atual->dir;
        }
        else // procura nos filhos da esquerda
        {
            atual = atual->esq;
        }
    }
}

struct NO *remove_atual(struct NO *atual)
{
    struct NO *no1, *no2;
    if(atual->esq == NULL) // n� com 1 filho ou sem filhos
    {
        no2 = atual->dir; // aponta para o dilho da direita
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL) // procura o filho mais a esquerda da arvore
    {
        no1 = no2;
        no2 = no2->dir;
    }
    if(no1 != atual)
    {
        // copia o filho mais a direita na �rvore para o lugar que foi removido
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

int consulta_arvBin(ArvBin *raiz, int valor)
{
    if(raiz == NULL) // verifica se a �rvore � valida
    {
        return 0;
    }
    struct NO *atual = *raiz;
    while(atual != NULL) // procura na �rvore at� chegar no fim
    {
        if(valor == atual->info) // achou o n�
        {
            return 1;
        }
        if(valor >atual->info) // procura no lado direito
        {
            atual = atual->dir;
        }
        else // procura no lado esquerdo
        {
            atual = atual->esq;
        }
    }
    return 0;
}
