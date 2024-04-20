#include <stdio.h>
#include <stdlib.h>

int main()
{
    int iH, iM, iS, duracao, tH, tM, tS;

    printf("Digite a hora de inicio: ");
    scanf("%d", &iH);
    printf("Digite os minutos de inicio: ");
    scanf("%d", &iM);
    printf("Digite os segundos de inicio: ");
    scanf("%d", &iS);
    printf("Informe a duracao do experimento em segundos: ");
    scanf("%d", &duracao);

    tH = duracao / (60 * 60);
    tM = (duracao / 60) - tH * 60;
    tS = duracao - (tH * 60 * 60) - (tM * 60);

    tH += iH;
    tM += iM;
    tS += iS;

    printf("Horario de termino do experimento: %dh%dm%ds", tH, tM, tS);

    printf("\n\n");
    system("pause");
    return 0;
}
