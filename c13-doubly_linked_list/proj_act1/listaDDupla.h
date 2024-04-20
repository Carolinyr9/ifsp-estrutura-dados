typedef struct aluno{
    int matricula;
    float n1, n2, n3;
}ALUNO;

typedef struct elemento *Lista;

Lista *criaLista();

int tamanho_lista(Lista *li);

int lista_cheia(Lista *li);

int lista_vazia(Lista *li);

int insere_lista_inicio(Lista *li, ALUNO al);

int insere_lista_final(Lista *li, ALUNO al);

int insere_lista(Lista *li, ALUNO al);

int consulta_lista_pos(Lista *li, int pos, ALUNO *al);

int consulta_lista_mat(Lista *li, int mat, ALUNO *al);

int remove_lista_inicio(Lista *li);

int remove_lista_final(Lista *li);

int remove_lista(Lista *li, int mat);

void destroi_lista(Lista *li);

