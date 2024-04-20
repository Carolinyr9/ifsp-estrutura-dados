#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v1 = 10;
    int v2 = 20;

    if(&v1 > &v2)
    {
        printf("\n\nO maior endereco e de v1: %p", &v1);
    }
    else
    {
        printf("\n\nO maior endereco e de v2: %p", &v2);
    }

    printf("\n\n");
    system("pause");
    return 0;
}
