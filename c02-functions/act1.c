#include <stdio.h>
#include <stdlib.h>

float salarioBruto, salarioFamilia, vantagens, inss, irpf, deducoes;

void calculoVantagens(int numeroHoras, float salarioHora, int numeroFilhos, float valorPorFilho);
void calculoDeducoes(float taxaIR);

int main()
{
    int numeroHoras, numeroFilhos;
    float taxaIR = 0.27, salarioHora, valorPorFilho;

    printf("Calculo de Vantagens e Deducoes de Um Funcionario\n\n\n");

    printf("Informe o numero de horas trabalhadas: ");
    scanf("%d", &numeroHoras);
    printf("Informe o valor da hora trabalhada (R$): ");
    scanf("%f", &salarioHora);
    printf("Informe o numero de filhos: ");
    scanf("%d", &numeroFilhos);
    printf("Informe o valor de vantagem por filho (R$): ");
    scanf("%f", &valorPorFilho);

    calculoVantagens(numeroHoras, salarioHora, numeroFilhos, valorPorFilho);
    calculoDeducoes(taxaIR);

    printf("\n\nSalario Bruto: R$%.2f", salarioBruto);
    printf("\nBeneficio Familia: R$%.2f", salarioFamilia);
    printf("\nDeducao - INSS: R$%.2f", inss);
    printf("\nDeducao - IRPF: R$%.2f", irpf);
    printf("\nTotal de Deducoes: R$%.2f", deducoes);

    printf("\n\nSalario Bruto + Vantagens: R$%.2f", vantagens);
    printf("\nSalario Liquido: R$%.2f", vantagens - deducoes);

    printf("\n\n");
    system("pause");
    return 0;
}

void calculoVantagens(int numeroHoras, float salarioHora, int numeroFilhos, float valorPorFilho)
{
    salarioBruto = numeroHoras * salarioHora;
    salarioFamilia = numeroFilhos * valorPorFilho;
    vantagens = salarioBruto + salarioFamilia;
}

void calculoDeducoes(float taxaIR)
{
    inss = salarioBruto * 0.08;
    irpf = salarioBruto * taxaIR;
    deducoes = inss + irpf;
}
