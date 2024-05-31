#include <stdio.h>
#include <stdlib.h>
#include "arvoreAVL.h"

struct NO {
    int info;
    int alt; // FB - altura da sub-arvore
    struct NO *esq;
    struct NO *dir;
};

// FUnções auxiliares internas

// Calcula a altura de um nó
int alt_no(struct NO *no){
    if(no == NULL){
        return -1;
    }else{
        reurn no->alt;
    }
}

// Devolve o maior entre dois valores
int maior(int x, int y){
    if( x > y) {
        return(x);
    } else {
        return(y);
    }
}

// Calcula o fator de balenceamento de um nó
int fatorBalanceamento_NO(struct NO *no){
    return abs(alt_no(no->esq) - alt_no(no->dir)); // a função abs() converte o valor passado em seu parametro para o
                                                  // valor absoluto ou seja, sem sinal
}

void rotacaoLL(arvAVL *A){
    struct NO *B;
    B = (*A)->esq;
    (*A)->esq = B->dir;
    B->dir  *A;
    (*A)->alt = maior(alt_no((*A)->esq), alt_no((*A)->dir)) + 1;
    B->alt = maior(alt_no(B->esq), (*A)->alt) + 1;
    *A = B;
}

void rotacaoRR(arvAVL *A){
    struct NO *B;
    B = (*A)->dir;
    (*A)->dir = B->esq;
    B->esq = (*A);
    (*A)->alt = maior(alt_no((*A)->esq), alt_no((*A)->dir)) + 1;
    B->alt = maior(alt_no(B->dir), (*A)->alt) + 1;
    (*A) = B;
}

