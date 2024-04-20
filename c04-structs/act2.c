#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario
{
    int id;
    char nome[30];
    int idade;
    float salario;
}FUNC;

FUNC coletaDados(void);
void imprimeDados(FUNC funcs[], int size);
void reajustaSalario(float *sal);
void rel_salario_corrigido(FUNC funcs[], int size);

int main()
{
    FUNC funcs[5];

    //Coleta Funcionarios
    for(int i = 0; i < 5; i++)
    {
        funcs[i] = coletaDados();
        printf("\n");
    }

    system("cls");

    //Imprime Funcionarios com aumento
    rel_salario_corrigido(funcs, 5);

    printf("\n\n\n");
    system("pause");
    return 0;
}

FUNC coletaDados()
{
    //Cria variavel tipo FUNC (que é um struct)
    FUNC f;

    //Povoa FUNC
    printf("\nInforme o ID da pessoa colaboradora: ");
    scanf(" %d", &f.id);

    fflush(stdin);
    printf("Informe o nome da pessoa colaboradora: ");
    fgets(f.nome, 29, stdin);
    f.nome[
        strlen(f.nome)- 1
    ] = '\0';

    printf("Informe a idade da pessoa colaboradora: ");
    scanf(" %d", &f.idade);

    printf("Informe o salario da pessoa colaboradora: ");
    scanf(" %f", &f.salario);

    // Retorna FUNC
    return f;
}

void imprimeDados(FUNC funcs[], int size)
{
    printf("\n\nDados das pessoas colaboradoras da empresa X");
    for(int i = 0; i < size; i++)
    {
        printf("\n\n\tColaborador %d:", i+1);
        printf("\n\t\tID ......: %d", funcs[i].id);
        printf("\n\t\tNome ....: %s", funcs[i].nome);
        printf("\n\t\tIdade ...: %d", funcs[i].idade);
        printf("\n\t\tSalario .: R$%.2f", funcs[i].salario);
    }
}

void reajustaSalario(float *sal)
{
    //Aumenta em 10% o salario
    *sal *= 1.1;
}

void rel_salario_corrigido(FUNC funcs[], int size)
{
    printf("\n\nSalarios dos colaboradores com reajuste de 10%:");
    for(int i = 0; i < size; i++)
    {
        //Reajusta salário
        reajustaSalario(&funcs[i].salario);

        //Imprime funcionario e seu novo salario na tela
        printf("\n\n\tColaborador %d:", funcs[i].id);
        printf("\n\t\tNome ..........: %s", funcs[i].nome);
        printf("\n\t\tNovo Salario ..: R$%8.2f", funcs[i].salario);
    }
}

