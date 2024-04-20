#include <stdio.h>
#include <stdlib.h>

int main()
{
    int idade, ano, nascimento;

    printf("Digite sua idade: ");
    scanf("%d", &idade);
    printf("Digite o ano atual: ");
    scanf("%d", &ano);

    nascimento = ano - idade;

    printf("\n\nVoce nasceu em: %d", nascimento);

    printf("\n\n");
    system("pause");
    return 0;
}
