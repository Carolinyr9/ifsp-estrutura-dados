#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "projetoFinal.h"

//Struct possuindo os dados cliente e seu próximo elemento
struct elemento{
    CLIENTE dados;
    struct elemento *prox;
};

typedef struct elemento ELEM;

// Cria a lista e aloca memoria
Lista *criaLista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){ // Se a alocação tiver dado certo,
        *li = NULL; // atribui NULL ao conteúdo de 'li'
    }

    return li;
}

// Libera a memória e apaga a lista e os elementos criados
void apagaLista(Lista *li){
    if(li != NULL){
        ELEM *no;
        while((*li) != NULL){   // Enquanto a lista não estiver vazia
            no = *li;           //é executado o while, que apaga os elementos até
            *li = (*li)->prox;  //que a lista esteja vazia
            free(no);
        }
        free(li);               // No final, é liberado o 'li'
    }
}

// Retorna o tamanho da lista
int tamLista(Lista *li){
    if(li == NULL){
        return 0;
    }
    int acum = 0;
    ELEM *no = *li;    // O 'no' recebe o primerio contato da lista
    while(no != NULL){ // Enquanto existir algo na lista, é acumulado um valor no 'acum'
        acum++;        //e depois o "nó" é atribuido com seu próximo elemento
        no = no->prox; //e então verificado consecutivamente
    }
    return acum;
}

// Avisa se a lista está vazia
int listaVazia(Lista *li){
    if(li == NULL){ // Se a lista não existir
        return 1;
    }
    if(*li == NULL){ // Se a lista estiver vazia sem nenhum elemento
        return 1;
    }
    return 0;
}

void pegaClientesArquivo(Lista *li, CLIENTE *cli){
    // Abre o arquivo no modo de leitura
    FILE *f;
    f = fopen("projetoAcme.txt", "rb");

    // Verifica se o arquivo foi aberto corretamente
    if(f == NULL){
        printf("\t\tErro ao abrir o arquivo!\n\n");
        system("pause");
        exit(1);
    }

    // Lê os dados do arquivo e insere na lista usando a função insereDados
    while(fread(cli, sizeof(CLIENTE), 1, f)){
        insere_lista_ordenada(li, *cli);
    }

    // Fecha o arquivo após a leitura
    fclose(f);
}


// Insere os elementos ordenadamente
int insere_lista_ordenada(Lista *li, CLIENTE cli){
    if(li == NULL){
        return 0;
    }

    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no == NULL){
        return 0;
    }
    no->dados = cli;
    if(listaVazia(li)){     // Verifica não tem nada na lista, se não tiver nada
        no->prox = (*li);   // o próximo endereço é atribuido ao "li",
        *li = no;           // e depois o "li" passa a ser o elemento atual, sendo o primeiro da lista
        return 1;
    } else {
        ELEM *ant, *atual = *li;
        while(atual != NULL && atual->dados.codigo < cli.codigo){
        /* Se existir um elemento na lista, é rodado o while
        até o código do elemento atual ser menor que o código inserido pelo o usuário*/
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){       // Insere se o elemento estiver na primeira posição
            no->prox = (*li);
            *li = no;
        } else {                // Caso contrário, insere em qualquer posição
            no->prox = ant->prox;
            ant->prox = no;
        }

        return 1;
    }
}

// Remove elemento pelo codigo
int remove_lista(Lista *li, int cod){
    if(li == NULL){
        return 0;
    }
    ELEM *ant, *no = *li;
    while(no != NULL && no->dados.codigo != cod){
    /*Enquanto existir um elemento na lista e este tiver o código menor
    do que o inserido pelo o usuário, é rodado o while*/
        ant = no;
        no = no->prox;
    }

    if(no == NULL){
        return 0;
    }
    if(no == *li){      // Se o elemento estiver na primeira posição
        *li = no->prox; //o 'li' recebe o próximo conteúdo do 'no', que é nulo
    } else {                    // Caso contrário, o conteúdo anterior vai apontar
        ant->prox = no->prox;   //para o elemento seguinte ao 'no', que é nulo
    }
    free(no);
    return 1;
}


int consulta_lista_pos(Lista *li, int posicao, CLIENTE *cli){
    if(li == NULL || posicao <= 0){
        return 0;
    }
    ELEM *no = *li;
    int i = 1;
    // percorre a lista com i a procura do elemento
    while(no != NULL && i < posicao){
        no = no->prox;
        i++;
    }

    // trata-se da lista vazia, ou não encontrou o elemento
    if(no == NULL){
        return 0;
    } else{
    // se no != de NULL, então encontrou o elemento
        *cli = no->dados;
        return 1;
    }
}

// Consulta um elemento pelo seu ID
int consulta_lista_id(Lista *li, int id, CLIENTE *cli){
    if(li == NULL){ // Verifica se a lista existe
        return 0;
    }
    ELEM *no = *li;
    while(no != NULL && no->dados.codigo != id){
    /* É rodado o while se o 'no' não estiver vazio e se o código do elemento
    for menor do que o inserido pelo o usuário*/
        no = no->prox;
    }
    if(no == NULL){
    // Se o 'no' estiver vazio, retorna 0
        return 0;
    } else {
    // Se estiver com elemento, os dados do elemento são passados para o 'al'
        *cli = no->dados;
        return 1;
    }
}

// Inserir dados do struct cliente
struct cliente coletaDados() {
    struct cliente cli;

    printf("\n\n\tNovo cliente...\n\n");

    printf("Digite o codigo: ");
    scanf("%d", &cli.codigo);

    // Limpa o buffer de entrada
    while (getchar() != '\n');

    printf("Digite o nome: ");
    fgets(cli.nome, sizeof(cli.nome), stdin);
    cli.nome[strcspn(cli.nome, "\n")] = '\0';
    for (int i = 0; cli.nome[i]; i++) {
        cli.nome[i] = tolower(cli.nome[i]); //deixa o nome em minúsculo
    }

    printf("Digite o nome da empresa: ");
    fgets(cli.empresa, sizeof(cli.empresa), stdin);
    cli.empresa[strcspn(cli.empresa, "\n")] = '\0';

    printf("Digite o departamento: ");
    fgets(cli.departamento, sizeof(cli.departamento), stdin);
    cli.departamento[strcspn(cli.departamento, "\n")] = '\0';

    printf("Digite o telefone: ");
    fgets(cli.telefone, sizeof(cli.telefone), stdin);
    cli.telefone[strcspn(cli.telefone, "\n")] = '\0';

    printf("Digite o celular: ");
    fgets(cli.celular, sizeof(cli.celular), stdin);
    cli.celular[strcspn(cli.celular, "\n")] = '\0';

    printf("Digite o email: ");
    fgets(cli.email, sizeof(cli.email), stdin);
    cli.email[strcspn(cli.email, "\n")] = '\0';

    return cli;
}

// Pega os dados do elemento que o usuário deseja editar para depois serem editados
struct cliente editaDados(CLIENTE cli){

    // Limpa o buffer de entrada
    while (getchar() != '\n');

    printf("Digite o nome: ");
    fgets(cli.nome, sizeof(cli.nome), stdin);
    cli.nome[strcspn(cli.nome, "\n")] = '\0';
    for (int i = 0; cli.nome[i]; i++) {
        cli.nome[i] = tolower(cli.nome[i]); //deixa o nome em minúsculo
    }

    printf("Digite o nome da empresa: ");
    fgets(cli.empresa, sizeof(cli.empresa), stdin);
    cli.empresa[strcspn(cli.empresa, "\n")] = '\0';

    printf("Digite o departamento: ");
    fgets(cli.departamento, sizeof(cli.departamento), stdin);
    cli.departamento[strcspn(cli.departamento, "\n")] = '\0';

    printf("Digite o telefone: ");
    fgets(cli.telefone, sizeof(cli.telefone), stdin);
    cli.telefone[strcspn(cli.telefone, "\n")] = '\0';

    printf("Digite o celular: ");
    fgets(cli.celular, sizeof(cli.celular), stdin);
    cli.celular[strcspn(cli.celular, "\n")] = '\0';

    printf("Digite o email: ");
    fgets(cli.email, sizeof(cli.email), stdin);
    cli.email[strcspn(cli.email, "\n")] = '\0';

    return cli;

}

// Gera um relatório da lista toda
void geraRelatorio(Lista *li) {
    if(listaVazia(li)){
        printf("\nErro: Lista vazia!\n");
    } else {
        ELEM *no = *li;
        int i = 1;

        while (no != NULL) {
            CLIENTE cl = no->dados;
            //Enquanto tiver elementos, é chamada a função imprimeDados para imprimir os elementos
            printf("\n\n\t\tCliente %d\n\n", i);
            imprimeDados(cl);
            no = no->prox;
            i++;
        }
    }

}

// Gera um relatório de apenas um elemento pelo nome digitado
void relatorioIndividualNome(Lista *li) {
    if (li == NULL || *li == NULL) {
        printf("Erro: Lista vazia\n");
        return;
    }

    char nome[50];
    printf("\nDigite o nome: ");
    scanf(" %s", nome);

    int i;

    // Deixa o nome digitado pelo usuário em letra minúscula
    for (i = 0; nome[i]; i++) {
        nome[i] = tolower(nome[i]);
    }

    CLIENTE cl;
    ELEM *no = *li;
    int acum = 0;

    i = 1;
    while (no != NULL) {
    /* Enquanto o 'no' não for nulo, o nome que está no 'no' vai ser comparado com o
    nome digitado pelo usuário, se esses forem iguais, os dados do 'no' são passados
    para 'cl' que depois vira parâmetro para chamar a função imprimeDados */
        if (strcmp(no->dados.nome, nome) == 0) {
            cl = no->dados;
            printf("\n\n\t\tCliente encontrado %d\n\n", i);
            imprimeDados(cl);
            i++;
        } else {
        // Se os nomes não forem iguais 'acum' é acumulado.
            acum++;
        }

        no = no->prox;
    }

    // Se 'acum' for igual ao tamanho da lista é exibido a mensagem abaixo
    if(acum == tamLista(li)){
        printf("Nome nao encontrado\n");
    }

}

// Gera um relatório de apenas um elemento pelo ID digitado
void relatorioIndividualId(Lista *li) {
    int i, x;
    printf("\nDigite o codigo de identificacao: ");
    scanf("%d", &i);
    CLIENTE cl;

    /* A função consulta_lista_id é chamada para pegar os dados e depois esses são
    armazenados em 'cl' */
    x = consulta_lista_id(li, i, &cl);
    if (x) {
    // Caso a consulta dê certo é exbido os dados pela função imprimeDados
        imprimeDados(cl);
    } else {
        printf("\nNao foi possivel consultar a posicao desejada\nMotivos: O codigo fornecido nao e valido, o cliente pode ter sido excluido anteriormente, a lista pode estar vazia, etc\n");
    }
}

// Imprime os dados de um elemento
void imprimeDados(CLIENTE cl){
        printf("Codigo......: %d\n", cl.codigo);
        printf("Nome........: %s\n", cl.nome);
        printf("Empresa.....: %s\n", cl.empresa);
        printf("Departamento: %s\n", cl.departamento);
        printf("Telefone....: %s\n", cl.telefone);
        printf("Celular.....: %s\n", cl.celular);
        printf("E-mail......: %s\n", cl.email);
}

// Edita os dados de um elemento a partir dos dados inseridos usando a função editarDados(CLIENTE al)
void editaCli(Lista *li) {
   ELEM* edita = *li;
    int codigo;
    printf("\nDigite o codigo de identificacao: ");
    scanf("%d", &codigo);


    while (edita != NULL) {
    /* Enquanto tiver elementos na lista, se o código do dado que o usuário deseja editar for igual ao dado informado
    é chamada a função editaDados e os dados são editados*/
        if (edita->dados.codigo == codigo) {
                CLIENTE cl = edita->dados;
                imprimeDados(cl);
                printf("\n\n");
                edita->dados = editaDados(edita->dados);
                printf("\nModificacoes salvas!\n");
                return;
        }
        edita = edita->prox;
    }
        printf("\nCliente com o codigo %d não encontrado na lista.\n", codigo);
}


// Função criada somente para a exibição do menu
void exibirMenu() {
    system("cls");
    printf("\t\tBem-vindo(a) a empresa ACME S.A\n\n");
    printf("\nDigite a opcao desejada conforme as seguintes:\n");
    printf("0 - Sair do programa;\n");
    printf("1 - Insercao de novo contato;\n");
    printf("2 - Gerar e exibir relatorio de contatos;\n");
    printf("3 - Gerar e exibir relatorio individual com busca por identificador;\n");
    printf("4 - Gerar e exibir relatorio com busca por nome;\n");
    printf("5 - Edicao de dados do contato, escolhido por identificador;\n");
    printf("6 - Remover contato, escolhido por identificador;\n");
    printf("\nOpcao desejada: ");
}

/* Função criada para dar o poder de escolha de uma das opções
do menu, a partir da escolha, são chamadas as funções específicas
para cada caso */
void menu(int codigo, Lista *li) {
    char opcao;
    struct cliente novoCliente;
    int x;

    do {
        exibirMenu();
        scanf(" %c", &opcao);
        int cod;

        switch (opcao) {
            //Encerra o programa
            case '0':
                printf("\n\t\tPrograma encerrando...\n");
                break;

            // Insere um novo contato
            case '1':
                system("cls");
                novoCliente = coletaDados();
                insere_lista_ordenada(li, novoCliente);
                system("pause");
                break;

            // Gera um relatório dos elementos da lista
            case '2':
               // printf("\n\t\tGerando relatorio de contatos...\n");
                system("cls");
                geraRelatorio(li);
                system("pause");
                break;

            // Gera um relatório individual de apenas um indivíduo por seu código
            case '3':
                system("cls");
                printf("\n\t\tGerando relatorio individual - Busca por Codigo\n");
                relatorioIndividualId(li);
                system("pause");
                break;

            // Gera um relatório indiviual de apenas um indivíduo por seu nome
            case '4':
                system("cls");
                printf("\n\t\tGerando relatorio individual - Busca por Nome\n");
                relatorioIndividualNome(li);
                system("pause");
                break;

            // Edita um contato
            case '5':
                system("cls");
                printf("\n\t\tEdicao de Contatos\n");
                editaCli(li);
                system("pause");
                break;

            // Remove um elemento da lista
            case '6':
                printf("Digite o codigo de identificacao do cliente que deseja excluir: ");
                scanf("%d", &cod);
                x = remove_lista(li, cod);
                if(x){
                    printf("Removido o elemento com sucesso!\n");
                } else {
                    printf("Nao foi possivel remover o elemento!\n");
                }
                system("pause");
                break;

            default:
                printf("Selecione uma opcao valida\n");
        }

    } while (opcao != '0');
}

// Grava elementos em um arquivo binário
int gravaArquivo(Lista *li, FILE *f) {
    if (li == NULL) {
        return 0; // Lista vazia ou nula
    }

    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no == NULL){
        return 0;
    }
    no = *li;
    while(no != NULL) {
    /* Enquanto existir elemento na lista, os dados são gravados em um arquivo binário */
        fwrite(no, sizeof(ELEM), 1, f);
        no = no->prox;
    }

    return 1;
}
