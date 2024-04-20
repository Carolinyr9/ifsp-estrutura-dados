#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float amigo1=0, amigo2=0, amigo3=0, investimentototal, premiototal=0, premioamigo1, premioamigo2, premioamigo3;

    printf("Informe quanto deu o amigo 1: ");
    scanf("%f", &amigo1);
    printf("Informe quanto deu o amigo 2: ");
    scanf("%f", &amigo2);
    printf("Informe quanto deu o amigo 3: ");
    scanf("%f", &amigo3);
    printf("Informe o premiototal: ");
    scanf("%f", &premiototal);

    investimentototal = amigo1 + amigo2 + amigo3;
    premioamigo1 = (amigo1 / investimentototal) * premiototal;
    premioamigo2 = (amigo2 / investimentototal) * premiototal;
    premioamigo3 = (amigo3 / investimentototal) * premiototal;

    printf("\n\nO amigo 1 deve ganhar: R$ %.2f", premioamigo1);
    printf("\nO amigo 2 deve ganhar: R$ %.2f", premioamigo2);
    printf("\nO amigo 3 deve ganhar: R$ %.2f", premioamigo3);

    printf("\n\n");
    system("pause");
    return 0;
}
