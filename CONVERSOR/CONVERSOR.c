#include <stdio.h>
#include <locale.h>
////////////////////////////////////////////
int binario(int decimal);
char *hexadecimal(int decimal);
int octal(int decimal);
////////////////////////////////////////////
int main(void) 
{
    setlocale(LC_ALL,"portuguese");
    int decimal;
    int base;
    printf("Digite um número decimal: ");
    scanf("%d", &decimal);

    printf("Digite a base para a qual deseja converter (2 para binário, 16 para hexadecimal e 8 para octal): ");
    scanf("%d", &base);

    switch(base) 
    {
        case 2:
            printf("O número decimal %d em binário é: %d\n", decimal, binario(decimal));
            break;
        case 16:
            printf("O número decimal %d em hexadecimal é: %s\n", decimal, hexadecimal(decimal));
            break;
        case 8:
            printf("O número decimal %d em octal é: %o\n", decimal, octal(decimal));
            break;
        default:
            printf("Base inválida\n");
            break;
    }

    return 0;
}
////////////////////////////////////////////
int binario(int decimal) 
{
    int binary = 0, base = 1;
    while (decimal > 0) {
        binary += (decimal % 2) * base;
        decimal /= 2;
        base *= 10;
    }
    return binary;
}
////////////////////////////////////////////
char *hexadecimal(int decimal) 
{
    static char hexadecimall[32];
    sprintf(hexadecimall, "%X", decimal);
    return hexadecimall;
}
////////////////////////////////////////////
int octal(int decimal) 
{
    int octall = 0, base = 1;
    while (decimal > 0) {
        octall += (decimal % 8) * base;
        decimal /= 8;
        base *= 10;
    }
    return octall;
}
