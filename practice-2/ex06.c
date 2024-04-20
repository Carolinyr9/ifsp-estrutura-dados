#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int somar_array(int v[], int i);

int main()
{
    //int v[10] = {2, 4, 6, 8, 10, -2, -4, -16, -8, -1};
    int v[10] = {2, 2, 2, 2, 2, 5, 5, 5, 5, -25};

    printf("Soma dos elementos do array= %d", somar_array(v, 0));

    printf("\n\n");
    system("pause");
    return 0;
}

int somar_array(int v[10], int i)
{
    if(i >= 9)
    {
        return v[i];
    }
    else
    {
        return (v[i] + somar_array(v, i+1));
    }
}


