#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//int numero_de_digitos(int n);
//int numero_invertido_try(int n);
void numero_invertido(int n);

int main()
{
    int n;

    printf("Digite um valor inteiro: ");
    scanf("%d", &n);

    system("cls");

    printf("Numero lido= %d\n", n);
    printf("\nNumero invertido= ");
    numero_invertido(n);

    printf("\n\n");
    system("pause");
    return 0;
}

void numero_invertido(int n)
{
    if(n / 10 < 1)
    {
        printf("%d", n);
    }
    else
    {
        printf("%d", n % 10);
        numero_invertido(n / 10);
    }
}

/*
//Calcula numero de digitos de um numero
//int casas = log10(n)+1);
int numero_de_digitos(int n)
{
    int i = 0;
    if (n == 0)
        i = 1;
    else
        while (n != 0)
        {
            i++;
            n /= 10;
        }
    return i;
}

int numero_invertido_try(int n)
{
    int d = numero_de_digitos(n);
    if(d == 1)
        return n;
    return (((n % 10) * (10 * (d - 1))) + numero_invertido_try(n / 10));
}
*/

