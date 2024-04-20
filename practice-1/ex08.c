#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    printf("\n%d -> %d -> %d", num-1, num, num+1);

    printf("\n\n");
    system("pause");
    return 0;
}
