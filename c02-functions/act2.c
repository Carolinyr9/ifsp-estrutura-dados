#include <stdio.h>
#include <stdlib.h>

void calculoVantagens(float *salarioBruto, float *salarioFamilia, float *vantagens, int numeroHoras, float salarioHora, int numeroFilhos, float valorPorFilho);
void calculoDeducoes(float *salarioBruto, float *inss, float *irpf, float *deducoes, float taxaIR);

int main()
{
    int numeroHoras, numeroFilhos;
    float taxaIR = 0.27, salarioHora, valorPorFilho;
    float salarioBruto, salarioFamilia, vantagens, inss, irpf, deducoes; //ex globais

    printf("Calculo de Vantagens e Deducoes de Um Funcionario\n\n\n");

    printf("Informe o numero de horas trabalhadas: ");
    scanf("%d", &numeroHoras);
    printf("Informe o valor da hora trabalhada (R$): ");
    scanf("%f", &salarioHora);
    printf("Informe o numero de filhos: ");
    scanf("%d", &numeroFilhos);
    printf("Informe o valor de vantagem por filho (R$): ");
    scanf("%f", &valorPorFilho);

    calculoVantagens(&salarioBruto, &salarioFamilia, &vantagens, numeroHoras, salarioHora, numeroFilhos, valorPorFilho);
    calculoDeducoes(&salarioBruto, &inss, &irpf, &deducoes, taxaIR);

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

void calculoVantagens(float *salarioBruto, float *salarioFamilia, float *vantagens, int numeroHoras, float salarioHora, int numeroFilhos, float valorPorFilho)
{
    *salarioBruto = numeroHoras * salarioHora;
    *salarioFamilia = numeroFilhos * valorPorFilho;
    *vantagens = *salarioBruto + *salarioFamilia;
}

void calculoDeducoes(float *salarioBruto, float *inss, float *irpf, float *deducoes, float taxaIR)
{
    *inss = *salarioBruto * 0.08;
    *irpf = *salarioBruto * taxaIR;
    *deducoes = *inss + *irpf;
}
