#include <stdio.h>
#include <stdlib.h>

int main()
{
    float sal;

    printf("Informe o salario: ");
    scanf("%f", &sal);

    printf("Novo salario com aumento: R$%.2f", sal * 1.25);

    printf("\n\n");
    system("pause");
    return 0;
}
