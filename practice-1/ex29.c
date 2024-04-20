#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float x, y, distancia, mx, my;

    printf("Informe o ponto x: ");
    scanf("%f", &x);
    printf("informe o ponto y: ");
    scanf("%f", &y);

    // Modulo dos pontos
    mx = x < 0 ? -x : x;
    my = y < 0 ? -y : y;

    distancia = pow((pow(mx, 2) + pow(my, 2)), 0.5);

    printf("\n\nO ponto (%.2f,%.2f) se encontra a aproximadamente %.2f de distancia do ponto (0,0)", x, y, distancia);

    printf("\n\n");
    system("pause");
    return 0;
}
