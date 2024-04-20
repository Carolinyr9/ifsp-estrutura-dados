#include <stdio.h>
#include <stdlib.h>

int main(){
    char letra = 'A';
    for(int i = 0; i < 26; i++)
    {
        printf(" %c", letra + i);
    }

    printf("\n\n");
    system("pause");
    return 0;
}
