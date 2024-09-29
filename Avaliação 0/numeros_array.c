#include <stdio.h>

int main()
{
    int numeros[5];
    int soma = 0;

    for (int i = 0; i < 5; i++)
    {
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &numeros[i]);
        soma += numeros[i];
    }

    printf("A soma total é: %d\n", soma);

    return 0;
}
