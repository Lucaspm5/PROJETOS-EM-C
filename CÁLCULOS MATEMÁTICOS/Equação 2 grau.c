#include <stdio.h>
#include <math.h>

int main(int argc, char const **argv) {
    float a, b, c, x1, x2;

    printf("Digite o valor de a: ");
    scanf("%f", &a);

    printf("Digite o valor de b: ");
    scanf("%f", &b);

    printf("Digite o valor de c: ");
    scanf("%f", &c);

    x1 = (-b + sqrt(b*b - 4*a*c)) / (2*a);
    x2 = (-b - sqrt(b*b - 4*a*c)) / (2*a);

    printf("As raízes da equação %fx^2 + %fx + %f = 0 são: %f e %f\n", a, b, c, x1, x2);

    return 0;
}
