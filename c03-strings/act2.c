#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nome[20], sobrenomes[20], ultimonome[20], nomecompleto[100] = "", empty[10] = " ";

    printf("Informe o nome: ");
    gets(nome);
    printf("Informe o ultimo nome: ");
    gets(ultimonome);
    printf("Informe os sobrenomes antes do ultimo nome: ");
    gets(sobrenomes);

    strcat(nomecompleto, nome);
    strcat(nomecompleto, empty);
    strcat(nomecompleto, sobrenomes);
    strcat(nomecompleto, empty);
    strcat(nomecompleto, ultimonome);

    printf("\n\nNome completo concatenado: %s", nomecompleto);

    printf("\n\n");
    system("pause");
    return 0;
}
