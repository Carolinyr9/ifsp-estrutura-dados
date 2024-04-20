#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char frase[100], consoante, letra;
    int contavogal = 0;

    printf("Digite uma consoante: ");
    consoante = getchar();
    fflush(stdin); //limpando buffer
    printf("Digite uma frase: ");
    gets(frase);

    for(int i = 0; i < strlen(frase); i++)
    {
        switch(frase[i])
        {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                contavogal++;
                frase[i] = consoante;
                break;
            default:
                break;
        }
    }

    printf("\nTotal de vogais: %d", contavogal);
    printf("\nString sem vogais: %s", frase);

    printf("\n\n");
    system("pause");
    return 0;
}
