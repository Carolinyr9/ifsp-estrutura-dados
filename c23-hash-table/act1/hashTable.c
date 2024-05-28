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
    Hash *ha = (Hash*) malloc(sizeof(Hash)); // alocar memoria
    if(ha != NULL) // se a alocação deu certo
    {
        int i;
        ha->TABLE_SIZE = TABLE_SIZE; // associar o tamanho da tabela
        // criar um vetor para guardar os itens
        ha->itens = (struct aluno**) malloc (TABLE_SIZE * sizeof(struct aluno*));

        // caso tenha dado errado, libera o item alocado e retorna nulo
        if(ha->itens == NULL)
        {
            free(ha);
            return NULL;
        }

        // em cada posição colocamos nulo, porque não temos nenhum elemento ainda
        ha->qtd = 0;
        for(i = 0; i < ha->TABLE_SIZE; i++)
        {
            ha->itens[i] = NULL;
        }
    }
    return ha;
}

void liberaHash(Hash *ha){
    if(ha != NULL){ // verifica se a tabela é válida
        int i;
        // percorre todas as posições da tabela hash e vai liberando
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
    // método da divisão
    // consiste em calcular o resto da divisão de um valor inteiro
    // que representa o elemento pelo tamanho da tabela
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
    // 0x7FFFFFFF - elimina i bit de sinal do valor da chave
    // evita o risco de ocorrer um overflow e obtermos um
    // número negativo
}

int chaveMultiplicacao(int chave, int TABLE_SIZE){
    // método da multiplicação
    // usar um valor "A", sendo 0 < A < 1, para multiplicar
    // o valor da chave que representa o elemento
    // a parte fracionaria resultante dessa multiplicação é
    // novamente multiplicada pelo tamanho da tabela
    float A = 0.6180339887; // constante multiplicativa
    float val = chave * A;
    val = val - (int) val; // extrai a parte fracionária
    return (int) (TABLE_SIZE * val);
}

int chaveDobra(int chave, int TABLE_SIZE){
    // método da dobra
    // utiliza o esquema de dobrar e somar os dígitos do valor
    // para calcular sua posição, normalmente usamos a operação
    // com valores binários e OU EXCLUSIVO
    int num_bits = 10;
    int parte1 = chave >> num_bits;
    int parte2 = chave & (TABLE_SIZE - 1);
    return (parte1 ^ parte2);
}

int valorSting(char *str){
    // para chaves que são strings, nós extraimos seus valores
    // a partir da tabela ascii e multiplicamos a depender de
    // sua posição (já que existem anagramas)
    int i, valor = 7;
    int tam = strlen(str);
    for(i = 0; i < tam; i++){
        // normalmente multiplicamos por 31
        valor = 31 * valor + (int) str[i];
    }
    return valor;
}

int insereHash_semColisao(Hash *ha, struct aluno al){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE){ // verifica se é válido
        return 0;
    }
    // calcular a posição e inserir o elemento
    int chave = al.matricula; // chave escolhida
    int pos = chaveDivisao(chave, ha->TABLE_SIZE);
    struct aluno *novo;
    novo = (struct aluno*) malloc(sizeof(struct aluno));
    if(novo == NULL){ // verifica se a alocação deu certo
        return 0;
    }
    *novo = al;
    ha->itens[pos] = novo; // guardar o aluno na posição pos da tabela
    ha->qtd++;
    return 1;
}

int buscaHash_semColisao(Hash *ha, int mat, struct aluno *al){
    if(ha == NULL){ // verifica se a tabela existe
        return 0;
    }
    int pos = chaveDivisao(mat, ha->TABLE_SIZE); // calcula a posição
    if(ha->itens[pos] == NULL){ // verifica a posição tem alguém alocado
        return 0; // deu errado
    }
    *al = *(ha->itens[pos]); // copia a posição para o ponteiro passado
    return 1; // deu certo
}

int sondagemLinear(int pos, int i, int TABLE_SIZE){
    // tenta calcular uma nova posição a partir da posição inicial
    return ((pos + i) & 0x7FFFFFFF) % TABLE_SIZE;
}

int sondagemQuadratica(int pos, int i, int TABLE_SIZE){
    // calcula a nova posição utilizando uma equação do segundo grau
    // gera um problema de agrupamento secundário
    pos = pos + 2 * i+ 5 * i * i;
    return (pos & 0x7FFFFFFF) & TABLE_SIZE;
}

int duploHash(int H1, int chave, int i, int TABLE_SIZE){
    // tenta espalhar os elementos usando duas funções de hash
    int H2 = chaveDivisao(chave, TABLE_SIZE - 1) + 1;
    return ((H1 + i * H2)  & 0x7FFFFFFF) % TABLE_SIZE;
}

int insereHash_enderecoAberto(Hash *ha, struct aluno al){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE){ // verifica se a lista é válida
        return 0;
    }
    int chave = al.matricula; // chave escolhida
    int i, pos, newpos;
    pos = chaveDivisao(chave, ha->TABLE_SIZE); // posição inicial da chave
    for(i = 0; i < ha->TABLE_SIZE; i++){ // roda até o fim da tabela
        newpos = sondagemLinear(pos, i, ha->TABLE_SIZE); // nova posição
        if(ha->itens[newpos] == NULL){ // verifica se tem algum item nessa posição
            struct aluno *novo;
            novo = (struct aluno*) malloc(sizeof(struct aluno));
            if(novo == NULL){ // erro na alocação
                return 0;
            }
            *novo = al;
            ha->itens[newpos] = novo;
            ha->qtd++;
            return 1; // alocação deu errado
        }
    }
    return 0; // falha na inserção

int buscaHash_enderecoAberto(Hash *ha, int mat, struct aluno *al){
    if(ha == NULL){ // verifica se a tabela é valida
        return 0;
    }
    int i, pos, newpos;
    pos = chaveDivisao(mat, ha->TABLE_SIZE); // calcula a posição
    for(i = 0; i < ha->TABLE_SIZE; i++){
        newpos = sondagemLinear(pos, i, ha->TABLE_SIZE); // calcula a nova posição
        if(ha->itens[newpos] == NULL){ // vê se tem alguem nessa posição
            return 0; // falha na busca, não tem como não tem ninguém, já que estamos usando a sondagem linear
        }
        if(ha->itens[newpos]->matricula == mat){ // verifica se realmente é a chave que estamos procurando
            *al = *(ha->itens[newpos]);
            return 1; // busca deu certo
        }
    }
    return 0; // falha na busca
}


