#include <stdio.h>

void fatorar(int num) 
{
    int fator = 2;

    while(num > 1)
    {
        if(num % fator == 0)
        {
            printf("%d ", fator);
            num /= fator;
        }else{
            fator++;
        }
    }
    printf("\n");
}

int main(int argc, char const **argv) 
{
    int num;
    int casos = 100;

    while(1)
    {
        printf("Digite um numero inteiro positivo para fatorar: ");
        scanf("%d", &num);

        printf("Os fatores primos de %d sao: ", num);

        fatorar(num);
    }
    return 0;
}
