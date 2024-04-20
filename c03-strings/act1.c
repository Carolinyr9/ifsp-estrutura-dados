#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    char nome[30];
    int idade;
    float sal;

    printf("Informe o nome: ");
    gets(nome);
    printf("Informe a idade: ");
    scanf("%d", &idade);
    printf("Informe o salario: ");
    scanf("%f", &sal);

    printf("\n\nTrabalhador: %s\nIdade: %d\nSalario: R$%.2f", nome, idade, sal);

    printf("\n\n");
    system("pause");
    return 0;
}
