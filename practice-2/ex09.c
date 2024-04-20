#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v1, v2, *p_v1, *p_v2;

    printf("Digite um valor inteiro: ");
    scanf(" %d", &v1);
    fflush(stdin);
    printf("Digite mais um valor inteiro: ");
    scanf(" %d", &v2);

    p_v1 = &v1;
    p_v2 = &v2;

    if(p_v1 > p_v2)
    {
        printf("\n\nO maior endereco e: %p e seu valor e: %d", p_v1, *p_v1);
    }
    else
    {
        printf("\n\nO maior endereco e: %p e seu valor e: %d", p_v2, *p_v2);
    }

    printf("\n\n");
    system("pause");
    return 0;
}

