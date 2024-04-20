#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valores[3];

    for(int i = 0; i < 3; i++)
    {
        printf("\n Digite um valor inteiro: ");
        scanf("%d", &valores[i]);
    }

    printf("\n\nSoma= %d", valores[0]+valores[1]+valores[2]);

    printf("\n\n");
    system("pause");
    return 0;
}
