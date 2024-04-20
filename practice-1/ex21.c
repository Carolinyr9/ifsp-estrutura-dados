#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float alturaDegrau, alturaAlvo;
    int degrausNecessarios;

    printf("Informe a altura do degrau (cm): ");
    scanf("%f", &alturaDegrau);
    printf("Informe a altura que deseja alcancar: ");
    scanf("%f", &alturaAlvo);

    degrausNecessarios = ceil(alturaAlvo / alturaDegrau);

    printf("\nSubir %d degraus para atingir a altura alvo!", degrausNecessarios);

    printf("\n\n");
    system("pause");
    return 0;
}
