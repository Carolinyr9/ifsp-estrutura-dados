#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str1[100], str2[100], *pointer;

    printf("Digite a frase 1: ");
    gets(str1);
    printf("Digite a frase 2: ");
    gets(str2);

    pointer = strstr(str1, str2);
    if(pointer != NULL)
    {
        printf("A frase 2 \"%s\" esta contida na frase 1 \"%s\"", str2, str1);
    }
    else
    {
        printf("A frase 2 \"%s\" nao esta contida na frase 1 \"%s\"", str2, str1);
    }

    printf("\n\n");
    system("pause");
    return 0;
}
