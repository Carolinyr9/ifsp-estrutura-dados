#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaSequencial.h"

int main()
{
    int x, i, qntAlunos = 10; //sera usado para codigo de erro
    int mat = 110, posicao = 1;
    Lista *li;
    ALUNO al, al2, al3, dados_aluno;

    li = cria_lista();

    // Inserir alunos padrões
    al.matricula = 100;
    al.n1 = 5.3;
    al.n2 = 6.9;
    al.n3 = 7.4;

    al2.matricula = 120;
    al2.n1 = 5.3;
    al2.n2 = 6.9;
    al2.n3 = 7.4;

    al3.matricula = 110;
    al3.n1 = 5.3;
    al3.n2 = 6.9;
    al3.n3 = 7.4;

    x = tamanho_lista(li);
    printf("\nTamanho da lista e: %d", x);

    x = lista_cheia(li);
    if(x)
    {
        printf("\nLista cheia!");
    }
    else
    {
        printf("\nLista nao esta cheia!");
    }

    x = lista_vazia(li);
    if(x)
    {
        printf("\nLista vazia!");
    }
    else
    {
        printf("\nLista nao esta vazia!");
    }

    x = insere_lista_final(li, al2);
    if(x)
    {
        printf("\nAluno inserido com sucesso!");
    }
    else
    {
        printf("\nErro aluno nao inserido!");
    }

    x = insere_lista_inicio(li, al);
    if(x)
    {
        printf("\nAluno inserido com sucesso!");
    }
    else
    {
        printf("\nErro aluno nao inserido!");
    }

    x = insere_lista_ordenada(li, al3);
    if(x)
    {
        printf("\nAluno inserido com sucesso!");
    }
    else
    {
        printf("\nErro aluno nao inserido!");
    }

    // pedir 10 alunos ordenamente
    for(i = 0; i < qntAlunos; i++)
    {
        al = cria_aluno();
        x = insere_lista_ordenada(li, al);
        if(x)
        {
            printf("\nAluno inserido com sucesso!");
        }
        else
        {
            printf("\nErro aluno nao inserido!");
        }
    }

    x = remove_lista_final(li);
    if(x)
    {
        printf("\nAluno removido no final com sucesso!");
    }
    else
    {
        printf("\nErro aluno nao removido!");
    }

    x = remove_lista_inicio(li);
    if(x)
    {
        printf("\nAluno removido do inicio com sucesso!");
    }
    else
    {
        printf("\nErro aluno nao removido!");
    }

    x = remove_lista(li, mat);
    if(x)
    {
        printf("\nAluno removido na posicao especificada com sucesso!");
    }
    else
    {
        printf("\nErro aluno nao removido na posicao especificada!");
    }

    x = consulta_lista_pos(li, posicao, &dados_aluno);
    if(x)
    {
        printf("\nConsulta por posicao realizada com sucesso!");
        printf("\nMatricula: %d", dados_aluno.matricula);
        printf("\nNota 1: %.2f", dados_aluno.n1);
        printf("\nNota 2: %.2f", dados_aluno.n2);
        printf("\nNota 3: %.2f", dados_aluno.n3);
    }
    else
    {
        printf("\nNao foi possivel consultar na posicao especificada!");
    }

    x = consulta_lista_mat(li, mat, &dados_aluno);
    if(x)
    {
        printf("\nConsulta por matricula realizada com sucesso!");
        printf("\nMatricula: %d", dados_aluno.matricula);
        printf("\nNota 1: %.2f", dados_aluno.n1);
        printf("\nNota 2: %.2f", dados_aluno.n2);
        printf("\nNota 3: %.2f", dados_aluno.n3);
    }
    else
    {
        printf("\nNao foi possivel consultar a matricula especificada!");
    }

    libera_lista(li);

    printf("\n\n");
    system("pause");
    return 0;
}
