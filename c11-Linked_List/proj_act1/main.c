#include <stdio.h>
#include <stdlib.h>
#include "listaLigada.h"

int main()
{
    ALUNO al1, al2, al3, al;
    Lista *li;
    int x = 0, matricula = 110, posicao = 2; //Para testar

    // Inserir alunos padrões
    al1.matricula = 100;
    al1.n1 = 5.3;
    al1.n2 = 6.9;
    al1.n3 = 7.4;

    al2.matricula = 120;
    al2.n1 = 5.3;
    al2.n2 = 6.9;
    al2.n3 = 7.4;

    al3.matricula = 110;
    al3.n1 = 5.3;
    al3.n2 = 6.9;
    al3.n3 = 7.4;

    li = criaLista();

    // li = endereco em memoria
    // *li = acessa o que está apontando

    x = tamLista(li);
    printf("O tamanho da lista e: %d", x);

    if(listaCheia(li)){
        printf("\nLista esta cheia!");
    }else{
        printf("\nLista nao esta cheia.");
    }

    if(listaVazia(li)){
        printf("\nLista esta vazia!");
    }else{
        printf("\nLista nao esta vazia.");
    }

    x = insere_inicio_lista(li, al1);
    if(x){
        printf("\nInserido no inicio com sucesso!");
    }else{
        printf("\nNao foi possivel inserir no inicio");
    }

    x = insere_final_lista(li, al2);
    if(x){
        printf("\nInserido no final com sucesso!");
    }else{
        printf("\nNao foi possivel inserir no final.");
    }

    x = insere_lista_ordenada(li, al3);
    if(x){
        printf("\nInserido ordenadamente com sucesso!");
    }else{
        printf("\nNao foi possivel inserir ordenadamente.");
    }

    x = consulta_lista_pos(li, posicao, &al);
    if(x)
    {
        printf("\n\nConteudo na posicao %d:", posicao);
        printf("\n%d", al.matricula);
        printf("\n%.2f", al.n1);
        printf("\n%.2f", al.n2);
        printf("\n%.2f", al.n3);
    }
    else
    {
        printf("\nElemeneto %d nao encontrado.", posicao);
    }

    x = consulta_lista_mat(li, matricula, &al);
    if(x)
    {
        printf("\n\nConteudo de matricula %d:", matricula);
        printf("\n%d", al.matricula);
        printf("\n%.2f", al.n1);
        printf("\n%.2f", al.n2);
        printf("\n%.2f", al.n3);
    }
    else
    {
        printf("\nElemeneto %d nao encontrado.", matricula);
    }

    x = remove_inicio_lista(li);
    if(x){
        printf("\nRemovido do inicio com sucesso!");
    }else{
        printf("\nNao foi possivel remover do inicio.");
    }

    x = remove_final_lista(li);
    if(x){
        printf("\nRemovido do final com sucesso!");
    }else{
        printf("\nNao foi possivel remover do final.");
    }

    x = remove_lista(li, matricula);
    if(x){
        printf("\nElemento removido com sucesso!");
    }else{
        printf("\nNao foi possivel remover o elemento.");
    }

    system("cls");
    //Atividade do Slide
    int continuar = 1;
    char choice = '9';
    while(continuar)
    {
        printf("~~~~Menu Lista Ligada~~~~\n");
        printf("\n1 - Incluir aluno na Lista");
        printf("\n2 - Buscar aluno por matricula");
        printf("\n3 - Excluir aluno");
        printf("\n0 - Encerrar programa");
        printf("\n\nInforme a opcao desejada: ");
        scanf(" %c", &choice);
        system("cls");

        switch(choice)
        {
        case '1':
            al = coletadados();
            x = insere_lista_ordenada(li, al);
            if(x){
                printf("\nInserido ordenadamente com sucesso!");
            }else{
                printf("\nNao foi possivel inserir ordenadamente.");
            }
            printf("\n\n");
            system("pause");
            system("cls");
            break;
        case '2':
            printf("Informe a matricula do aluno que quer buscar: ");
            scanf("%d", &matricula);
            x = consulta_lista_mat(li, matricula, &al);
            if(x)
            {
                printf("\n\nConteudo de matricula %d:", matricula);
                printf("\n%d", al.matricula);
                printf("\n%.2f", al.n1);
                printf("\n%.2f", al.n2);
                printf("\n%.2f", al.n3);
            }
            else
            {
                printf("\nAluno %d nao encontrado.", matricula);
            }
            printf("\n\n");
            system("pause");
            system("cls");
            break;
        case '3':
            printf("Informe a matricula do aluno que quer excluir: ");
            scanf("%d", &matricula);
            x = remove_lista(li, matricula);
            if(x){
                printf("\nElemento removido com sucesso!");
            }else{
                printf("\nNao foi possivel remover o elemento.");
            }
            printf("\n\n");
            system("pause");
            system("cls");
            break;
        case '0':
            continuar = 0;
            break;
        default:
            printf("Escolha uma opcao valida no menu!");
            break;
        }
    }

    apagaLista(li);

    printf("\n\n");
    system("pause");
    return 0;
}
