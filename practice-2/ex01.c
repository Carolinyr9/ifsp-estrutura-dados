#include <stdio.h>
#include <stdlib.h>

void desenha(int n);

int main()
{
    int n;

    printf("Digite um inteiro positivo: ");
    scanf("%d", &n);

    system("cls");

    desenha(n);

    printf("\n\n\n");
    system("pause");
    return 0;
}

void desenha(int n)
{
    int count = 1;
    while(n > 0)
    {
        for(int i = 0; i < count; i++)
        {
            printf("!");
        }
        printf("\n");
        count++;
        n--;
    }
}
