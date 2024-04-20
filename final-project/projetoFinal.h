// Criação da estrutura cliente com os campos pedidos
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


// Libera a memória e apaga a lista e os elementos criados
void apagaLista(Lista *li);


// Retorna o tamanho da lista
int tamLista(Lista *li);


// Avisa se a lista está vazia
int listaVazia(Lista *li);

// Lê o arquivo e insere os elementos na lista ************************************
void pegaClientesArquivo(Lista *li, CLIENTE *cli);

// Insere os elementos ordenadamente
int insere_lista_ordenada(Lista *li, CLIENTE cli);


// Remove elemento pelo codigo
int remove_lista(Lista *li, int cod);


//
int consulta_lista_pos(Lista *li, int posicao, CLIENTE *cli);


// Inserir dados do struct cliente
struct cliente coletaDados();


// Pega os dados do elemento que o usuário deseja editar para depois serem editados
struct cliente editaDados(CLIENTE al);


// Gera um relatório da lista toda
void geraRelatorio(Lista *li);


// Gera um relatório de apenas um elemento pelo nome digitado
void relatorioIndividualNome(Lista *li);


// Gera um relatório de apenas um elemento pelo ID digitado
void relatorioIndividualId(Lista *li);


// Imprime os dados de um elemento
void imprimeDados(CLIENTE cl);


// Edita os dados de um elemento a partir dos dados inseridos usando a função editarDados(CLIENTE al)
void editaCli(Lista *li);


// Função criada somente para a exibição do menu
void exibirMenu();


/* Função criada para dar o poder de escolha de uma das opções
do menu, a partir da escolha, são chamadas as funções específicas
para cada caso */
void menu(int codigo, Lista *li);


// Grava elementos em um arquivo binário
int gravaArquivo(Lista *li, FILE *f);


int consulta_lista_id(Lista *li, int id, CLIENTE *cli);
