#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashTable.h" //inclui os prototipos

struct aluno coletadados()
{
    ALUNO al;
    char str[30];

    printf("\n\nInforme a matricula do aluno: ");
    scanf("%d", &al.matricula);
    fflush(stdin);

    printf("\nInforme o nome: ");
    fgets(str, 30, stdin);
    str[strlen(str)-1] = '\0';
    strcpy(al.nome, str);
    fflush(stdin);

    printf("\nInforme a nota 1: ");
    scanf("%f", &al.n1);

    printf("\nInforme a nota 2: ");
    scanf("%f", &al.n2);

    printf("\nInforme a nota 3: ");
    scanf("%f", &al.n3);

    return al;
}

void exibeAluno(ALUNO al)
{
    printf("\n\nMatricula: %d", al.matricula);
    printf("\nNome: %s", al.nome);
    printf("\nNota 1: %.2f", al.n1);
    printf("\nNota 2: %.2f", al.n2);
    printf("\nNota 3: %.2f", al.n3);
}

//definicao do tipo Hash - tipo opaco
struct hash{
    int qtd;
    int TABLE_SIZE;
    struct aluno **itens;
};

Hash *criaHash(int TABLE_SIZE)
{
    Hash *ha = (Hash*) malloc(sizeof(Hash));
    if(ha != NULL)
    {
        int i;
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (struct aluno**) malloc (TABLE_SIZE * sizeof(struct aluno*));

        if(ha->itens == NULL)
        {
            free(ha);
            return NULL;
        }

        ha->qtd = 0;
        for(i = 0; i < ha->TABLE_SIZE; i++)
        {
            ha->itens[i] = NULL;
        }
    }
    return ha;
}

void liberaHash(Hash *ha){
    if(ha != NULL){
        int i;
        for(i = 0; i < ha->TABLE_SIZE; i++){
            if(ha->itens[i] != NULL){
                free(ha->itens[i]);
            }
        }
        free(ha->itens);
        free(ha);
    }
}

int chaveDivisao(int chave, int TABLE_SIZE){
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}

int chaveMultiplicacao(int chave, int TABLE_SIZE){
    float A = 0.6180339887;
    float val = chave * A;
    val = val - (int) val;
    return (int) (TABLE_SIZE * val);
}

int chaveDobra(int chave, int TABLE_SIZE){
    int num_bits = 10;
    int parte1 = chave >> num_bits;
    int parte2 = chave & (TABLE_SIZE - 1);
    return (parte1 ^ parte2);
}

int valorSting(char *str){
    int i, valor = 7;
    int tam = strlen(str);
    for(i = 0; i < tam; i++){
        valor = 31 * valor + (int) str[i];
    }
    return valor;
}

int insereHash_semColisao(Hash *ha, struct aluno al){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE){
        return 0;
    }
    int chave = al.matricula;
    int pos = chaveDivisao(chave, ha->TABLE_SIZE);
    struct aluno *novo;
    novo = (struct aluno*) malloc(sizeof(struct aluno));
    if(novo == NULL){
        return 0;
    }
    *novo = al;
    ha->itens[pos] = novo;
    ha->qtd++;
    return 1;
}

int buscaHash_semColisao(Hash *ha, int mat, struct aluno *al){
    if(ha == NULL){
        return 0;
    }
    int pos = chaveDivisao(mat, ha->TABLE_SIZE);
    if(ha->itens[pos] == NULL){
        return 0;
    }
    *al = *(ha->itens[pos]);
    return 1;
}

int sondagemLinear(int pos, int i, int TABLE_SIZE){
    return ((pos + i) & 0x7FFFFFFF) % TABLE_SIZE;
}

int sondagemQuadratica(int pos, int i, int TABLE_SIZE){
    pos = pos + 2 * i+ 5 * i * i;
    return (pos & 0x7FFFFFFF) & TABLE_SIZE;
}

int duploHash(int H1, int chave, int i, int TABLE_SIZE){
    int H2 = chaveDivisao(chave, TABLE_SIZE - 1) + 1;
    return ((H1 + i * H2)  & 0x7FFFFFFF) % TABLE_SIZE;
}

int insereHash_enderecoAberto(Hash *ha, struct aluno al){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE){
        return 0;
    }
    int chave = al.matricula;
    int i, pos, newpos;
    pos = chaveDivisao(chave, ha->TABLE_SIZE);
    for(i = 0; i < ha->TABLE_SIZE; i++){
        newpos = sondagemLinear(pos, i, ha->TABLE_SIZE);
        if(ha->itens[newpos] == NULL){
            struct aluno *novo;
            novo = (struct aluno*) malloc(sizeof(struct aluno));
            if(novo == NULL){
                return 0;
            }
            *novo = al;
            ha->itens[newpos] = novo;
            ha->qtd++;
            return 1;
        }
    }
    return 0;
}

int buscaHash_enderecoAberto(Hash *ha, int mat, struct aluno *al){
    if(ha == NULL){
        return 0;
    }
    int i, pos, newpos;
    pos = chaveDivisao(mat, ha->TABLE_SIZE);
    for(i = 0; i < ha->TABLE_SIZE; i++){
        newpos = sondagemLinear(pos, i, ha->TABLE_SIZE);
        if(ha->itens[newpos] == NULL){
            return 0;
        }
        if(ha->itens[newpos]->matricula == mat){
            *al = *(ha->itens[newpos]);
            return 1;
        }
    }
    return 0;
}


