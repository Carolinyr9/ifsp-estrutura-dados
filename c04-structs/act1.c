#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct funcionario
{
    int id;
    char nome[30];
    int idade;
    float salario;
};

int main()
{
    struct funcionario funcs[5];

    for(int i = 0; i < 5; i++)
    {
        printf("\nInforme o ID da pessoa colaboradora %d: ", i+1);
        scanf(" %d", &funcs[i].id);

        fflush(stdin);
        printf("Informe o nome da pessoa colaboradora %d: ", i+1);
        fgets(funcs[i].nome, 29, stdin);
        funcs[i].nome[
            strlen(funcs[i].nome)- 1
        ] = '\0';

        printf("Informe a idade da pessoa colaboradora %d: ", i+1);
        scanf(" %d", &funcs[i].idade);

        printf("Informe o salario da pessoa colaboradora %d: ", i+1);
        scanf(" %f", &funcs[i].salario);
    }

    printf("\n\nDados das pessoas colaboradoras da empresa X");
    for(int i = 0; i < 5; i++)
    {
        printf("\n\n\tColaborador %d:", i+1);
        printf("\n\t\tID ......: %d", funcs[i].id);
        printf("\n\t\tNome ....: %s", funcs[i].nome);
        printf("\n\t\tIdade ...: %d", funcs[i].idade);
        printf("\n\t\tSalario .: R$%.2f", funcs[i].salario);
    }

    printf("\n\n\n");
    system("pause");
    return 0;
}

