#include <stdio.h>
#include <stdlib.h>
#include "arvoreLLBR.h"

#define RED 1
#define BLACK 0

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
    int cor;
};

int cor(struct NO *H){
    if(H == NULL){
        return BLACK;
    }else{
        return H->cor;
    }
}

void trocaCor(struct NO *H){
    H->cor = !H->cor;
    if(H->esq != NULL){
        H->esq->cor = !H->esq->cor;
    }
    if(H->dir != NULL){
        H->dir->cor = !H->dir->cor;
    }
}

struct NO *rotacionaEsquerda(struct NO *A){
    struct NO *B = A->dir;
    A->dir = B->esq;
    B->esq = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
};

struct NO *rotacionaDireita(struct NO *A){
    struct NO *B = A->esq;
    A->esq = B->dir;
    B->dir = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
};

struct NO *move2EsqRED(struct NO *H){
    trocaCor(H);
    if(cor(H->dir->esq) == RED){
        H->dir = rotacionaDireita(H->dir);
        H = rotacionaEsquerda(H);
        trocaCor(H);
    }
    return H;
};

struct NO *move2DirRED(struct NO *H){
    trocaCor(H);
    if(cor(H->esq->esq) == RED){
        H = rotacionaDireita(H);
        trocaCor(H);
    }
    return H;
};

struct NO *balancear(struct NO *H){
    if(cor(H->dir) == RED){
        H = rotacionaEsquerda(H);
    }
    if(H->esq != NULL && cor(H->dir) == RED && cor(H->esq->esq) == RED){
        H = rotacionaDireita(H);
    }
    if(cor(H->esq) == RED && cor(H->dir) == RED){
        trocaCor(H);
    }
    return H;
};

arvoreLLRB *cria_arvoreLLRB(){
    arvoreLLRB *raiz = (arvoreLLRB*) malloc(sizeof(arvoreLLRB));
    if(raiz != NULL){
        *raiz = NULL;
    }
    return raiz;
}

void libera_NO(struct NO *no){
    if(no == NULL){
        return;
    }
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void liberar_arvoreLLRB(arvoreLLRB *raiz){
    if(raiz == NULL){
        return;
    }
    libera_NO(*raiz);
    free(raiz);
}

int vazia_arvoreLLRB(arvoreLLRB *raiz){
    if(raiz == NULL){
        return 1;
    }
    if(*raiz == NULL){
        return 1;
    }
    return 0;
}

int altura_arvoreLLRB(arvoreLLRB *raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    int alt_esq = altura_arvoreLLRB(&((*raiz)->esq));
    int alt_dir = altura_arvoreLLRB(&((*raiz)->dir));
    if(alt_esq > alt_dir){
        return(alt_esq + 1);
    }else{
        return(alt_dir + 1);
    }
}

int totalNO_arvoreLLRB(arvoreLLRB *raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    int alt_esq = altura_arvoreLLRB(&((*raiz)->esq));
    int alt_dir = altura_arvoreLLRB(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

void preOrdem_arvoreLLRB(arvoreLLRB *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz == NULL){
        printf("%d\n", (*raiz)->info);
        preOrdem_arvoreLLRB(&((*raiz)->esq));
        preOrdem_arvoreLLRB(&((*raiz)->dir));
    }
}

void emOrdem_arvoreLLRB(arvoreLLRB *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz == NULL){
        emOrdem_arvoreLLRB(&((*raiz)->esq));
        printf("%d\n", (*raiz)->info);
        emOrdem_arvoreLLRB(&((*raiz)->dir));
    }
}

void posOrdem_arvoreLLRB(arvoreLLRB *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz == NULL){
        posOrdem_arvoreLLRB(&((*raiz)->esq));
        posOrdem_arvoreLLRB(&((*raiz)->dir));
        printf("%d\n", (*raiz)->info);
    }
}

consulta_arvoreLLRB(arvoreLLRB *raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    struct NO *atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            return 1;
        }
        if(valor > atual->info){
            atual = atual->dir;
        }else{
            atual = atual->esq;
        }
    }
    return 0;
}
