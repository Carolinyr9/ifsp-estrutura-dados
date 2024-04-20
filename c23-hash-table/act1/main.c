#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h" //inclui os prototipos

int main()
{
    int treat_crash = -1, mat;
    char choice;
    Hash *lista;
    ALUNO al;

    lista = criaHash(1024);

    do
    {
        printf("~~~~~~ Escolha a Tabela Hash desejada: ~~~~~~");
        printf("\n1 - Com tratamento de colisao");
        printf("\n2 - Sem tratamento de colisao");
        printf("\n0 - Sair do programa");
        printf("\nInforme o numero da acao que deseja: ");
        fflush(stdin);
        scanf(" %c", &choice);
        system("cls");

        switch(choice)
        {
        case '1':
            treat_crash = 1;
            break;
        case '2':
            treat_crash = 0;
            break;
        case '0':
            break;
        default:
            printf("Escolha um numero de acao valido no menu!\n\n");
            printf("\n\n");
            system("pause");
            system("cls");
            break;
        }

        if(treat_crash != -1)
        {
            do
            {
                if(treat_crash)
                {
                    printf("~~~~~~ Tabela Hash com tratamento de colisao ~~~~~~\n");
                    printf("1 - Inserir aluno\n");
                    printf("2 - Buscar aluno\n");
                    printf("0 - Sair do programa\n");
                    printf("\nInforme o numero da acao que deseja: ");
                    fflush(stdin); // Para garantir que somente o que o usuario digitar sera guardado
                    scanf(" %c", &choice);
                    system("cls");

                    switch(choice)
                    {
                    case '1':
                        if(insereHash_enderecoAberto(lista, coletadados()))
                        {
                            printf("Aluno inserido com sucesso!");
                        }
                        else
                        {
                            printf("ErroR: Falha ao inserir aluno!");
                            system("pause");
                            exit(1);
                        }
                        break;
                    case '2':
                        printf("Informe a matricula do aluno: ");
                        scanf("%d", &mat);
                        system("cls");

                        if(buscaHash_enderecoAberto(lista, mat, &al))
                        {
                            printf("Aluno encontrado!\n");
                            exibeAluno(al);
                        }
                        else
                        {
                            printf("Aluno de matricula %d nao encontrado!", mat);
                        }
                        break;
                    case '0':
                        break;
                    default:
                        printf("Escolha um numero de acao valido no menu!\n\n");
                        break;
                    }
                }
                else
                {
                    printf("~~~~~~ Tabela Hash sem tratamento de colisao ~~~~~~\n");
                    printf("1 - Inserir aluno\n");
                    printf("2 - Buscar aluno\n");
                    printf("0 - Sair do programa\n");
                    printf("\nInforme o numero da acao que deseja: ");
                    fflush(stdin); // Para garantir que somente o que o usuario digitar sera guardado
                    scanf(" %c", &choice);
                    system("cls");

                    switch(choice)
                    {
                    case '1':
                        if(insereHash_semColisao(lista, coletadados()))
                        {
                            printf("Aluno inserido com sucesso!");
                        }
                        else
                        {
                            printf("ErroR: Falha ao inserir aluno!");
                            system("pause");
                            exit(1);
                        }
                        break;
                    case '2':
                        printf("Informe a matricula do aluno: ");
                        scanf("%d", &mat);
                        system("cls");

                        if(buscaHash_semColisao(lista, mat, &al))
                        {
                            printf("Aluno encontrado!\n");
                            exibeAluno(al);
                        }
                        else
                        {
                            printf("Aluno de matricula %d nao encontrado!", mat);
                        }
                        break;
                    case '0':
                        break;
                    default:
                        printf("Escolha um numero de acao valido no menu!\n\n");
                        break;
                    }
                }

                if(choice != '0')
                {
                    printf("\n\n");
                    system("pause");
                    system("cls");
                }
            }
            while(choice != '0'); // Sair do menu quando usuario digitar 0
        }
    }
    while(choice != '0');

    liberaHash(lista);

    printf("\n\n");
    system("pause");
    return 0;
}
