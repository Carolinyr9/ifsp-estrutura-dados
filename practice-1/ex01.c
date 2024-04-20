#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroInteiro;
    float numeroReal;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numeroInteiro);
    printf("Inteiro digitado: %d \n\n", numeroInteiro);

    printf("Digite um numero real: ");
    scanf("%f", &numeroReal);
    printf("Real digitado: %.2f", numeroReal);

    printf("\n\n");
    system("pause");
    return 0;
}
