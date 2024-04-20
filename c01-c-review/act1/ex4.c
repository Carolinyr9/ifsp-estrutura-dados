#include <stdio.h>
#include <stdlib.h>

int main()
{
    char escolha;

    printf("Quer continuar? [sim - s / nao - n]: \n");
    scanf(" %c", &escolha);

    switch(escolha)
    {
    case 's':
    case 'S':
        printf("Voce quer continuar");
        break;
    case 'n':
    case 'N':
        printf("Voce quer parar");
        break;
    default:
        printf("Escolha invalida!");
        break;
    }

    printf("\n\n\n");
    system("pause");
    return 0;
}
