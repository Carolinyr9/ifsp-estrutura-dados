// Cria��o da estrutura cliente com os campos pedidos
typedef struct cliente {
    int codigo;
    char nome[50];
    char empresa[30];
    char departamento[30];
    char telefone[20];
    char celular[20];
    char email[40];
} CLIENTE;


typedef struct elemento* Lista;


// Cria a lista e aloca memoria para ser inserido os elementos dentro dela
Lista *criaLista();


// Libera a mem�ria e apaga a lista e os elementos criados
void apagaLista(Lista *li);


// Retorna o tamanho da lista
int tamLista(Lista *li);


// Avisa se a lista est� vazia
int listaVazia(Lista *li);

// L� o arquivo e insere os elementos na lista ************************************
void pegaClientesArquivo(Lista *li, CLIENTE *cli);

// Insere os elementos ordenadamente
int insere_lista_ordenada(Lista *li, CLIENTE cli);


// Remove elemento pelo codigo
int remove_lista(Lista *li, int cod);


//
int consulta_lista_pos(Lista *li, int posicao, CLIENTE *cli);


// Inserir dados do struct cliente
struct cliente coletaDados();


// Pega os dados do elemento que o usu�rio deseja editar para depois serem editados
struct cliente editaDados(CLIENTE al);


// Gera um relat�rio da lista toda
void geraRelatorio(Lista *li);


// Gera um relat�rio de apenas um elemento pelo nome digitado
void relatorioIndividualNome(Lista *li);


// Gera um relat�rio de apenas um elemento pelo ID digitado
void relatorioIndividualId(Lista *li);


// Imprime os dados de um elemento
void imprimeDados(CLIENTE cl);


// Edita os dados de um elemento a partir dos dados inseridos usando a fun��o editarDados(CLIENTE al)
void editaCli(Lista *li);


// Fun��o criada somente para a exibi��o do menu
void exibirMenu();


/* Fun��o criada para dar o poder de escolha de uma das op��es
do menu, a partir da escolha, s�o chamadas as fun��es espec�ficas
para cada caso */
void menu(int codigo, Lista *li);


// Grava elementos em um arquivo bin�rio
int gravaArquivo(Lista *li, FILE *f);


int consulta_lista_id(Lista *li, int id, CLIENTE *cli);
