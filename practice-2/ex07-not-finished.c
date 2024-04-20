#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
        int matricula;
        char nome[30];
        float n1;
        float n2;
        float n3;
} ALUNO;

int indice_de_aluno_com_maior_media(ALUNO alunos[]);

int main()
{
    ALUNO a[3];

    a[0].matricula = 1;
    strcpy(a[0].nome, "One Vinicius");
    a[0].n1 = 5;
    a[0].n2 = 5;
    a[0].n3 = 5;

    a[1].matricula = 2;
    strcpy(a[1].nome, "Two Barboza");
    a[1].n1 = 10;
    a[1].n2 = 10;
    a[1].n3 = 10;

    a[2].matricula = 2;
    strcpy(a[2].nome, "Three Rocha");
    a[2].n1 = 8;
    a[2].n2 = 8;
    a[2].n3 = 8;

    printf("Indice do aluno que possui a maior media geral entre todos alunos: %d", indice_de_aluno_com_maior_media(a));

    printf("\n\n");
    system("pause");
    return 0;
}

int indice_de_aluno_com_maior_media(ALUNO alunos[])
{
    int indice_maior_media = 0;
    float maior_media = 0;

    //int len = (sizeof(alunos) / sizeof(alunos[0]));
    int len = 3;

    for(int i = 0; i < len; i++)
    {
        float media = (alunos[i].n1 + alunos[i].n2 + alunos[i].n3) / 3;
        if(media > maior_media)
        {
            maior_media = media;
            indice_maior_media = i;
        }
    }

    return indice_maior_media;
}
