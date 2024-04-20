#include <stdio.h>
#include <stdlib.h>

int main()
{
    char matricula[10];
    float p1, p2, p3, mediaponderada;

    printf("Informe a matricula do aluno: ");
    gets(matricula);
    printf("Nota P1: ");
    scanf("%f", &p1);
    printf("Nota P2: ");
    scanf("%f", &p2);
    printf("Nota P3: ");
    scanf("%f", &p3);

    mediaponderada = (p1 + p2 + p3 * 2) / 4;

    printf("\n\nEstudante %s \nMedia: %f", matricula, mediaponderada);
    printf("\nStatus: %s", (mediaponderada >= 60 ? "Aprovade" : "Reprovade"));

    printf("\n\n");
    system("pause");
    return 0;
}
