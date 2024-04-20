#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int menor_valor(int v[10], int i, int *m);

int main()
{
    int v[10] = {2, 4, 6, 8, 10, -2, -4, -16, -8, -1};
    int menor = v[0];

    printf("%d", menor_valor(v, 0, &menor));

    printf("\n\n");
    system("pause");
    return 0;
}

int menor_valor(int v[10], int i, int *m)
{
    if(v[i] < *m)
    {
        *m = v[i];
    }

    if(i == 9)
        return *m;
    else
        return menor_valor(v, i+1, m);

}


