#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

Escreva um programa que leia uma string do teclado e converta todos os seus caracteres em
maiúscula. Não utilize nenhuma função da biblioteca <ctype.h>, subtraia o valor 32 dos
caracteres. Consulte a tabela ASCII para isso.

*/

int main()
{
    char str[100];
    int strlength = 0;

    printf("Digite uma frase: ");
    gets(str);

    strlength = strlen(str);

    for(int i = 0; i < strlength; i++)
    {
        if(str[i] >= 65 && str[i] <= 90)
        {
            str[i] += 32;
        }
    }

    printf("Frase completamente em minuscula: %s", str);

    printf("\n\n");
    system("pause");
    return 0;
}
