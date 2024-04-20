#include <stdio.h>
#include <stdlib.h>

int main()
{
    int totalseconds, seconds, minutes, hours;

    printf("Digite um valor inteiro em segundos: ");
    scanf("%d", &totalseconds);

    hours = totalseconds / 60 / 60;
    minutes = (totalseconds / 60) - hours * 60;
    seconds = totalseconds - (hours * 60 * 60) - (minutes * 60);

    printf("\n%ds equivale a: %dh%dm%ds", totalseconds, hours, minutes, seconds);

    printf("\n\n");
    system("pause");
    return 0;
}
