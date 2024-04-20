#include <stdio.h>
#include <stdlib.h>

int main()
{
    float premio = 780000;

    printf("O primeiro ganha: R$ %.2f", premio * 0.46);
    printf("\n\nO segundo ganha: R$ %.2f", premio * 0.32);
    printf("\n\nO terceiro ganha: R$ %.2f", premio * (1-0.46-0.32));

    printf("\n\n");
    system("pause");
    return 0;
}
