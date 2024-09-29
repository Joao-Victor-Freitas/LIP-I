#include <stdio.h>
#include <string.h>

int main()
{
    char string[100];
    int tamanho;

    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);

    tamanho = strlen(string);

    printf("A string tem %d caracteres.\n", tamanho - 1);

    return 0;
}
