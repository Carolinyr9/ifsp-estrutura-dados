#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *arq1, *arq2;
    char str[100], strLida[100] = "", c;

    // Receber string
    printf("Digite uma frase: ");
    fgets(str, 99, stdin);

    // Abre arquivo e verifica se foi aberto com sucesso
    arq1 = fopen("arq1.txt", "w");
    if(arq1 == NULL)
    {
        printf("\n\tErro ao abrir arq1.txt!\n");
        system("pause");
        exit(1);
    }

    // Grava a string, character a character
    for(int i = 0; i < strlen(str); i++)
    {
        fputc(str[i], arq1);
    }

    // Fecha arquivo
    fclose(arq1);

    //
    // Gera um novo arquivo com tudo em CAPS
    //

    // Abri arq1.txt no modo leitura
    arq1 = fopen("arq1.txt", "r");
    if(arq1 == NULL)
    {
        printf("\n\tErro ao abrir arq1.txt!\n");
        system("pause");
        exit(1);
    }

    // Guarda arquivo numa string
    for(int i = 0; i < strlen(str); i++)
    {
        strLida[i] = fgetc(arq1);
    }

    // Fecha arq1.txt
    fclose(arq1);

    // Abre arq2.txt no modo escrita
    arq2 = fopen("arq2.txt", "w");
    if(arq2 == NULL)
    {
        printf("\n\tErro ao abrir arq2.txt!\n");
        system("pause");
        exit(1);
    }

    // Grava a string, character a character maiusculo no arquivo
    for(int i = 0; i < strlen(strLida); i++)
    {
        fputc(toupper(strLida[i]), arq2);
    }

    // Fecha arquivo
    fclose(arq2);

    //
    // Imprime os dois arquivos em tela
    //
    printf("\n\narq1.txt\n");

    arq1 = fopen("arq1.txt", "r");
    if(arq1 == NULL)
    {
        printf("\n\tErro ao abrir arq1.txt!\n");
        system("pause");
        exit(1);
    }

    c = fgetc(arq1);
    while(c != EOF)
    {
        printf("%c", c);
        c = fgetc(arq1);
    }

    printf("\n\narq2.txt\n");

    arq2 = fopen("arq2.txt", "r");
    if(arq1 == NULL)
    {
        printf("\n\tErro ao abrir arq2.txt!\n");
        system("pause");
        exit(1);
    }

    c = fgetc(arq2);
    while(c != EOF)
    {
        printf("%c", c);
        c = fgetc(arq2);
    }



    printf("\n\n");
    system("pause");
    return 0;
}
