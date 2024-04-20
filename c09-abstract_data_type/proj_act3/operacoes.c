#include <stdio.h>
#include <stdlib.h>
#include "operacoes.h"

float resultado = 0;

float somar(float a, float b)
{
    resultado = a + b;
    return resultado;
}

float subtrair(float a, float b)
{
    resultado = a - b;
    return resultado;
}

float multiplicar(float a, float b)
{
    resultado = a * b;
    return resultado;
}

float dividir(float a, float b)
{
    resultado = a / b;
    return resultado;
}

float ultimoResultado()
{
    return resultado;
}
