#define MAX 100

typedef struct aluno{
    int matricula;
    float n1, n2, n3;
} ALUNO;

ALUNO cria_aluno();

typedef struct lista Lista;

Lista *cria_lista();

int tamanho_lista(Lista *li);

int lista_cheia(Lista *li);

int lista_vazia(Lista *li);

int insere_lista_final(Lista *li, struct aluno al);

int insere_lista_inicio(Lista *li, struct aluno al);

int insere_lista_ordenada(Lista *li, struct aluno al);

int remove_lista_final(Lista *li);

int remove_lista_inicio(Lista *li);

int remove_lista(Lista *li, int matricula);

//Busca por posi��o
int consulta_lista_pos(Lista *li, int pos, struct aluno *al);

//Busca por conte�do
int consulta_lista_mat(Lista *li, int mat, struct aluno *al);

void libera_lista(Lista *li);

